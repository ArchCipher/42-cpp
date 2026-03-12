#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define DOG_IDEAS 10

class Dog : public Animal
{
    Brain            *brain;
    const std::string dog_ideas[DOG_IDEAS] = {
        "woof... food...", "howl",       "play fetch",  "wag tail",
        "eat bone",        "take a nap", "go for walk", "dig a hole",
        "sniff...",        "chew toys"};
    void addDefaultIdeas();

  public:
    ~Dog();
    Dog();
    Dog(const Dog &copy);
    Dog               &operator=(const Dog &copy);

    const std::string &getIdea(unsigned int i) const;
    void               setIdea(const std::string &Idea, unsigned int i);

    void               makeSound() const override;
};

#endif
