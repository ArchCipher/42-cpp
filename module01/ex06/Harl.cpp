#include "Harl.hpp"

using std::cout;

void Harl::debug(void)
{
    cout << "[ DEBUG ]\n"
            "I love having extra bacon for my "
            "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
            "I really do!\n\n";
}

void Harl::info(void)
{
    cout << "[ INFO ]\n"
            "I cannot believe adding extra bacon costs more money.\n"
            "You didn’t put enough bacon in my burger!\n"
            "If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning(void)
{
    cout << "[ WARNING ]\n"
            "I think I deserve to have some extra bacon for free.\n"
            "I’ve been coming for years, whereas you started working here just "
            "last month.\n\n";
}

void Harl::error(void)
{
    cout << "[ ERROR ]\n"
            "This is unacceptable!\n"
            "I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;

    for (i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            break ;
    }
    
    switch (i)
    {
        default:
            cout << "[ Probably complaining about insignificant problems ]\n";
            break ;
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
    }
}
