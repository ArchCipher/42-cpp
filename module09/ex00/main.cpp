#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

/*
    This program the value of a certain amount of bitcoin on a certain date.
	
	It uses a database in csv format (data.csv) which will represent bitcoin
	price over time. It will take as input a second database, storing the
	different prices/dates to evaluate.

	• The program name is btc.
	• Your program takes a file as an argument.
	• Each line in this file must use the following format: "date | value".
	• A valid date will always be in the following format: Year-Month-Day.
	• A valid value must be a float or a positive integer, between 0 and 1000.
*/

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }
    std::ifstream input(av[1]);
    if (!input.is_open())
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }
    try
    {
        BitcoinExchange db("data.csv");
        std::string     line;
        std::getline(input, line); // skip header
        while (std::getline(input, line))
            db.getValue(line);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in database: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
