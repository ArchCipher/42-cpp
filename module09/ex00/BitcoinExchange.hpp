#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <sstream>

class BitcoinExchange
{
    std::map<std::string, float> db;

    void         fillMap(const std::string &line);
    static void  parse_key(std::stringstream &ss, std::string &key,
                           char separator);
    static bool  valid_date(const std::string &s);
    static float getFloat(const std::string &s);

  public:
    ~BitcoinExchange() {};
    BitcoinExchange(const std::string &infile);

    void getValue(const std::string &s);
};

#endif
