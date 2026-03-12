#include "Cat.hpp"

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete brain;
}

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    addDefaultIdeas();
    std::cout << "Cat constructor called\n";
}

// https://hackmd.io/@ChloeIsCoding/S1D-y80bll
void Cat::addDefaultIdeas()
{
    for (int i = 0; i < MAX_IDEAS; i++)
        brain->setIdea(cat_ideas[rand() % CAT_IDEAS], i);
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    brain = new Brain(*copy.brain);
    std::cout << "Cat copy constructor called\n";
}

// Note: brain = copy.brain is shallow copy (SEGV)
// deep copy : *brain = *copy.brain
Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        *brain = *copy.brain;
        std::cout << "Cat assignment operator called\n";
    }
    return (*this);
}

const std::string &Cat::getIdea(unsigned int i) const
{
    return (brain->getIdea(i));
}

void Cat::setIdea(const std::string &Idea, unsigned int i)
{
    brain->setIdea(Idea, i);
}

void Cat::makeSound() const
{
    std::cout << "Meow...\n";
}
