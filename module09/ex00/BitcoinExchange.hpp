#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
    std::map<std::string, float> db;

    static void  parse_key(std::stringstream &ss, std::string &key,
                           char separator);
    static bool  valid_date(const std::string &s);
    static float getFloat(const std::string &s);
    void         fillMap(std::string &line);

  public:
    ~BitcoinExchange() {};
    BitcoinExchange(const std::string &infile);

    void getValue(std::string &s);
};

#endif
