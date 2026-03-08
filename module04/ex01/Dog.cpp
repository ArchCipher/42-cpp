#include "Dog.hpp"
#include <ctime>

Dog::Dog() : Animal("Dog")
{
    brain = new Brain();
    addDefaultIdeas();
    std::cout << "Dog constructor called\n";
}

void Dog::addDefaultIdeas()
{
    for (int i = 0; i < MAX_IDEAS; i++)
        brain->setIdea(dog_ideas[rand() % DOG_IDEAS], i);
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    brain = new Brain(*copy.brain);
    std::cout << "Dog copy constructor called\n";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete brain;
}

// Note: brain = copy.brain is shallow copy (SEGV)
// deep copy : *brain = *copy.brain
Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        *brain = *copy.brain;
        std::cout << "Dog assignment operator called\n";
    }
    return (*this);
}

const std::string &Dog::getIdea(unsigned int i) const
{
    return (brain->getIdea(i));
}

void Dog::setIdea(const std::string &Idea, unsigned int i)
{
    brain->setIdea(Idea, i);
}

void Dog::makeSound() const
{
    std::cout << "Woof...\n";
}
