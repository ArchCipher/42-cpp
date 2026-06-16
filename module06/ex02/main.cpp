#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // rand, srand
#include <ctime>   // time
#include <iostream>

Base *generate(void)
{
    switch (std::rand() % 3)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

void display_type(char c)
{
    std::cout << c << '\n';
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        display_type('A');
    else if (dynamic_cast<B *>(p))
        display_type('B');
    else if (dynamic_cast<C *>(p))
        display_type('C');
    else
        std::cerr << "Could not find type\n";
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        display_type('A');
    }
    catch (const std::exception &)
    {
        try
        {
            (void)dynamic_cast<B &>(p);
            display_type('B');
        }
        catch (const std::exception &)
        {
            try
            {
                (void)dynamic_cast<C &>(p);
                display_type('C');
            }
            catch (const std::exception &)
            {
                std::cerr << "Could not find type\n";
            }
        }
    }
}

/*
        https://www.geeksforgeeks.org/cpp/dynamic-_cast-in-cpp/

        Indicates failed conversions through nullptr (for pointers) or
   std::bad_cast (for references).
*/

int main()
{
    std::srand(std::time(0));
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
}
