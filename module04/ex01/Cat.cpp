#include "Cat.hpp"

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete brain;
}

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    addDefaultIdeas();
    std::cout << "Cat constructor called\n";
}

void Cat::addDefaultIdeas()
{
    static const std::string cat_ideas[CAT_IDEAS] = {
        "meow... food...", "drink milk", "play with string", "lick paws",
        "eat fish",        "take a nap", "hide in box",      "purr on lap",
        "watch birds",     "scratch"};
    for (int i = 0; i < MAX_IDEAS; i++)
        brain->setIdea(cat_ideas[arc4random() % CAT_IDEAS], i);
}

Cat::Cat(const Cat &copy) : Animal(copy), brain(new Brain(*copy.brain))
{
    std::cout << "Cat copy constructor called\n";
}

/*
    REFERENCES:
        [C++ Orthodox Canonical Form]
        (https://hackmd.io/@ChloeIsCoding/S1D-y80bll)

    NOTE:
        brain = copy.brain is shallow copy (SEGV)
        deep copy : *brain = *copy.brain
*/
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

void Cat::setIdea(const std::string &idea, unsigned int i)
{
    brain->setIdea(idea, i);
}

void Cat::makeSound() const
{
    std::cout << "Meow...\n";
}
