#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called\n";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        std::cout << "Dog assignment operator called\n";
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof...\n";
}
