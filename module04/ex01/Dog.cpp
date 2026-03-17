#include "Dog.hpp"

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete brain;
}

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
    addDefaultIdeas();
    std::cout << "Dog constructor called\n";
}

void Dog::addDefaultIdeas()
{
    static const std::string dog_ideas[DOG_IDEAS] = {
        "woof... food...", "howl",       "play fetch",  "wag tail",
        "eat bone",        "take a nap", "go for walk", "dig a hole",
        "sniff...",        "chew toys"};
    for (int i = 0; i < MAX_IDEAS; i++)
        brain->setIdea(dog_ideas[arc4random() % DOG_IDEAS], i);
}

Dog::Dog(const Dog &copy) : Animal(copy), brain(new Brain(*copy.brain))
{
    std::cout << "Dog copy constructor called\n";
}

/*
        Note: brain = copy.brain is shallow copy (SEGV)
        deep copy : *brain = *copy.brain

        https://hackmd.io/@ChloeIsCoding/S1D-y80bll
*/
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

void Dog::setIdea(const std::string &idea, unsigned int i)
{
    brain->setIdea(idea, i);
}

void Dog::makeSound() const
{
    std::cout << "Woof...\n";
}
