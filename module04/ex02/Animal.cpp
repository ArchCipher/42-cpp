#include "Animal.hpp"

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

Animal::Animal()
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(std::string Type) : type(Type)
{
    std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
    std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
    {
        type = copy.type;
        std::cout << "Animal assignment operator called\n";
    }
    return (*this);
}

void Animal::setType(std::string Type)
{
    type = Type;
}

const std::string &Animal::getType() const
{
    return (type);
}
