#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string Type) : type(Type)
{
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type)
{
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
    {
        type = copy.type;
        std::cout << "WrongAnimal assignment operator called\n";
    }
    return (*this);
}

void WrongAnimal::setType(std::string Type)
{
    type = Type;
}

const std::string &WrongAnimal::getType() const
{
    return (type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes some sound...\n";
}
