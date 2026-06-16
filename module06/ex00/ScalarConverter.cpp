#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <sstream>

static void        handle_char_literal(const std::string &s);
static void        handle_numeric_literal(const std::string &s);

static void        print_from_double(double d);
static void        print_int_char(int i);
static std::string format_decimal(double d);
static void        print_all_impossible();

static bool        is_invalid(const std::string &s);
static bool        is_char_literal(const std::string &s);
static bool        is_impossible_as_char(int i);
static bool        is_impossible_as_int(double d);
static bool        is_impossible_as_float(double d);

ScalarConverter   &ScalarConverter::operator=(const ScalarConverter &)
{
    return (*this);
}

void ScalarConverter::convert(const std::string &s)
{
    if (is_invalid(s))
    {
        print_all_impossible();
        return;
    }
    if (is_char_literal(s))
    {
        handle_char_literal(s);
        return;
    }
    handle_numeric_literal(s);
}

static void handle_char_literal(const std::string &s)
{
    char c = s[0];
    print_int_char(static_cast<unsigned char>(c));
    std::cout << "float: " << static_cast<float>(c) << ".0f\n"
              << "double: " << static_cast<double>(c) << ".0\n";
}

/*
        stod exceptions:
                std::invalid_argument -> if no conversion could be performed
                std::out_of_range
*/
static void handle_numeric_literal(const std::string &s)
{
    size_t p = 0;
    try
    {
        double d = std::stod(s, &p);
        size_t len = s.length();
        if (p == len || (p == len - 1 && (s[p] == 'f' || s[p] == 'F')))
            print_from_double(d);
        else
            print_all_impossible();
    }
    catch (const std::exception &)
    {
        print_all_impossible();
    }
}

static void print_from_double(double d)
{
    if (is_impossible_as_int(d))
        std::cout << "char: impossible\n"
                  << "int: impossible\n";
    else
        print_int_char(static_cast<int>(d));
    std::string out = format_decimal(d);
    if (is_impossible_as_float(d))
        std::cout << "float: impossible\n";
    else
        std::cout << "float: " << out << "f\n";
    std::cout << "double: " << out << '\n';
}

static void print_int_char(int i)
{
    if (is_impossible_as_char(i))
        std::cout << "char: impossible\n";
    else if (!isprint(i))
        std::cout << "char: non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(i) << "'\n";
    std::cout << "int: " << i << '\n';
}

static std::string format_decimal(double d)
{
    std::ostringstream oss;
    oss << d;
    std::string out = oss.str();
    if (!std::isinf(d) && !std::isnan(d) &&
        out.find('.') == std::string::npos &&
        out.find('e') == std::string::npos &&
        out.find('E') == std::string::npos)
        out += ".0";
    return out;
}

static void print_all_impossible()
{
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: impossible\n"
              << "double: impossible\n";
}

static bool is_invalid(const std::string &s)
{
    return (s.empty() || (s.length() > 1 && isspace(s[0])));
}

/*
        Shell: use $'\n' (not '\n') so argv is one newline byte.
    './convert '\n'' passes backslash + n (length 2).
*/
static bool is_char_literal(const std::string &s)
{
    return (s.length() == 1 && !isdigit(s[0]));
}

static bool is_impossible_as_char(int i)
{
    return (i > CHAR_MAX || i < CHAR_MIN);
}

static bool is_impossible_as_int(double d)
{
    return (isnan(d) || d > INT_MAX || d < INT_MIN);
}

static bool is_impossible_as_float(double d)
{
    return (d != 0 && !std::isinf(d) &&
            (std::fabs(d) > FLT_MAX || std::fabs(d) < FLT_MIN));
}
