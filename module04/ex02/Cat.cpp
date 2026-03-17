#include "Cat.hpp"

void Cat::addDefaultIdeas()
{
    static const std::string cat_ideas[CAT_IDEAS] = {
        "meow... food...", "drink milk", "play with string", "lick paws",
        "eat fish",        "take a nap", "hide in box",      "purr on lap",
        "watch birds",     "scratch"};
    for (int i = 0; i < MAX_IDEAS; i++)
        brain->setIdea(cat_ideas[arc4random() % CAT_IDEAS], i);
}

Cat::~Cat()
{
    delete brain;
}

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    addDefaultIdeas();
}

Cat::Cat(const Cat &copy) : Animal(copy), brain(new Brain(*copy.brain)) {}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        *brain = *copy.brain;
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
