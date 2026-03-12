#include "WrongCat.hpp"

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
    {
        WrongAnimal::operator=(copy);
        std::cout << "WrongCat assignment operator called\n";
    }
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Meow...\n";
}
