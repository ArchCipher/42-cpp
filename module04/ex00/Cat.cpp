#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        std::cout << "Cat assignment operator called\n";
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow...\n";
}
