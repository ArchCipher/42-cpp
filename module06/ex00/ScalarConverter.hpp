#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

/*
        class ScalarConverter with static method "convert" that will take as a
        parameter a string representation of a C++ literal in its most common
   form and output its value in the following series of scalar types: • char •
   int • float • double

        This class cannot be instantiated.

        Except for char parameters, only the decimal notation can be converted.
        Examples of:
                char literals: ’c’, ’a’, ...
                int literals: 0, -42, 42...
                float literals: 0.0f, -4.2f, 4.2f...
                double literals: 0.0, -4.2, 4.2...

        Handles pseudo-literals: -inf, -inff, +inf, +inff, nan and nanf.
*/
class ScalarConverter
{
    ScalarConverter() {};
    ScalarConverter(const ScalarConverter &) {};
    ScalarConverter &operator=(const ScalarConverter &);

  public:
    virtual ~ScalarConverter() {};
    static void convert(const std::string &s);
};

#endif
