#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cerrno>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange(const std::string &infile)
{
    std::ifstream input(infile);
    if (!input.is_open())
        throw std::logic_error("could not open database file");
    std::string line;
    std::getline(input, line); // skip header
    while (std::getline(input, line))
        fillMap(line); // can throw
}

/*
    Each line should be in the format "Year-Month-Day | value"
    Avalid value must be either a float or a positive integer, between 0 & 1000
*/
void BitcoinExchange::getValue(const std::string &s)
{
    std::stringstream             ss(s);
    std::pair<std::string, float> kv_pair;
    try
    {
        parse_key(ss, kv_pair.first, '|');
        std::string value;
        std::getline(ss, value);
        kv_pair.second = getFloat(value); // can throw
        if (kv_pair.second > 1000)
            throw std::out_of_range("");
        std::map<std::string, float>::const_iterator it =
            db.lower_bound(kv_pair.first);
        if (it == db.end() || it->first != kv_pair.first)
        {
            if (it == db.begin())
            {
                std::cout << "Error: no data found" << " => " << kv_pair.first
                          << '\n';
                return;
            }
            it--;
        }
        float res = it->second * kv_pair.second;
        std::cout << kv_pair.first << " => " << kv_pair.second << " = " << res
                  << '\n';
    }
    catch (const std::invalid_argument &)
    {
        std::cout << "Error: bad input" << " => " << kv_pair.first << '\n';
    }
    catch (const std::out_of_range &)
    {
        std::cout << "Error: too large a number.\n";
    }
    catch (const std::logic_error &)
    {
        std::cout << "Error: not a positive number.\n";
    }
}

/*
    each line should be in the format "Year-Month-Day,exchange_rate"
*/
void BitcoinExchange::fillMap(const std::string &line)
{
    std::stringstream             ss(line);
    std::pair<std::string, float> kv_pair;
    parse_key(ss, kv_pair.first, ',');
    std::string value;
    std::getline(ss, value);
    try
    {
        kv_pair.second = getFloat(value); // can throw
        std::pair<std::map<std::string, float>::const_iterator, bool> res =
            db.insert(kv_pair);
        if (!res.second)
            throw std::logic_error("duplicate key");
    }
    catch (const std::exception &)
    {
        throw std::logic_error("invalid exchange_rate");
    }
}

static void rtrim(std::string &s)
{
    size_t last = s.find_last_not_of(' ');
    if (last == std::string::npos)
        s.clear();
    else
        s.erase(last + 1);
}

/*
static void ltrim(std::string &s)
{
    size_t first = s.find_first_not_of(' ');
	if (first != std::string::npos)
		s.erase(0, first);
}
*/

void BitcoinExchange::parse_key(std::stringstream &ss, std::string &key,
                                char separator)
{
    std::getline(ss, key, separator);
    rtrim(key);
    if (!valid_date(key))
        throw std::invalid_argument("invalid date");
}

/*
	Evenly divisible by 4, and
	- not evenly diviible by 100, or
	- even divisible by 100 and 400.
*/
static bool is_leap_year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

/*
	Valid date should be in the format Year-Month-Day
*/
bool BitcoinExchange::valid_date(const std::string &s)
{
    if (s.size() != 10)
        return false;
	if (s[4] != '-' || s[7] != '-')
		return false;
	for (size_t i = 0; i < 4; i++)
	{
		if (!std::isdigit(s[i]))
            return false;
	}
	if (!std::isdigit(s[5]) || !std::isdigit(s[6])
		|| !std::isdigit(s[8]) || !std::isdigit(s[9]))
		return false;
	int year = std::atoi(s.substr(0, 4).c_str());
	int month = std::atoi(s.substr(5, 2).c_str());
	int date = std::atoi(s.substr(8, 2).c_str());
    if (date < 1)
		return false;
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return (date <= 31);
		case 4: case 6: case 9: case 11:
			return (date <= 30);
		case 2:
			if (is_leap_year(year))
				return (date <= 29);
			return (date <= 28);	
		default:
			return false;	
	}
}

static float ft_stof(const std::string &s, size_t *idx)
{
    errno = 0;
    char *p = NULL;
    if (s.empty())
        throw std::invalid_argument("empty string");
    float f = std::strtof(s.c_str(), &p);
    if (errno == ERANGE)
        throw std::out_of_range("");
    if (*p)
        throw std::invalid_argument("invalid float");
    if (idx)
        *idx = static_cast<size_t>(p - s.c_str());
    return f;
}

float BitcoinExchange::getFloat(const std::string &s)
{
    float  f = ft_stof(s, NULL); // can throw
    if (f < 0)
        throw std::logic_error("invalid float");
    return f;
}
