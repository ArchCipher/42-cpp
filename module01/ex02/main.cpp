#include <iostream>

int main()
{
    std::string  s = "HI THIS IS BRAIN";
    std::string *ptr = &s;
    std::string &ref = s;

    std::cout << &s << ": address of string variable\n"
              << ptr << ": address of stringPTR\n"
              << &ref << ": address of stringREF\n";

    std::cout << s << ": value of string variable\n"
              << *ptr << ": value of stringPTR\n"
              << ref << ": value of stringREF\n";
}