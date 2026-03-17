#include "Animal.hpp"

Animal::Animal(const std::string &type) : type(type) {}

Animal::Animal(const Animal &copy) : type(copy.type) {}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
        type = copy.type;
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
