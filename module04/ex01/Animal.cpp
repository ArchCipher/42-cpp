#include "Animal.hpp"

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

Animal::Animal()
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const std::string &type) : type(type)
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

void Animal::setType(const std::string &my_type)
{
    type = my_type;
}

const std::string &Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const
{
    std::cout << "** Animal sound **\n";
}
