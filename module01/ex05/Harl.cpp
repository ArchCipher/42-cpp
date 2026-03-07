#include "Harl.hpp"

using std::cout;

void Harl::debug(void)
{
    cout << "I love having extra bacon for my "
            "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
            "I really do!\n";
}

void Harl::info(void)
{
    cout << "I cannot believe adding extra bacon costs more money.\n"
            "You didn’t put enough bacon in my burger!\n"
            "If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
    cout << "I think I deserve to have some extra bacon for free.\n"
            "I’ve been coming for years, whereas you started working here just "
            "last month.\n";
}

void Harl::error(void)
{
    cout << "This is unacceptable!\n"
            "I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*func_ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                      &Harl::error};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*func_ptr[i])();
            return;
        }
    }
}
