#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(const std::string &infile)
{
    std::ifstream input(infile);
    if (!input.is_open())
        throw std::exception(); // should throw "could not open database file.";
    std::string line;
    std::getline(input, line); // skip header
    while (std::getline(input, line))
        fillMap(line); // can throw
}

/*
    each line should be in the format "Year-Month-Day,exchange_rate"
*/
void BitcoinExchange::fillMap(std::string &line)
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

/*
    Each line should be in the format "Year-Month-Day | value"
    Avalid value must be either a float or a positive integer, between 0 & 1000
*/
void BitcoinExchange::getValue(std::string &s)
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
                std::cerr << "Error: no data found" << " => " << kv_pair.first
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
        std::cerr << "Error: bad input" << " => " << kv_pair.first << '\n';
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "Error: too large a number.\n";
    }
    catch (const std::logic_error &)
    {
        std::cerr << "Error: not a positive number.\n";
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
	valid date should be in the format Year-Month-Day
*/
bool BitcoinExchange::valid_date(std::string &s)
{
    if (s.size() != 10)
        return false;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (s[i] != '-')
                return false;
        }
        else if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

/*
    std::stof exceptions:
        std::invalid_argument
        std::out_of_range
*/
float BitcoinExchange::getFloat(std::string &s)
{
    size_t p = 0;
    float  f = std::stof(s, &p); // can throw
    if (f < 0)
        throw std::logic_error("");
    if (s[p])
        throw std::invalid_argument("");
    return f;
}
