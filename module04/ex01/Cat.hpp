#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define CAT_IDEAS 10

class Cat : public Animal
{
    Brain            *brain;
    const std::string cat_ideas[CAT_IDEAS] = {
        "meow... food...", "drink milk", "play with string", "lick paws",
        "eat fish",        "take a nap", "hide in box",      "purr on lap",
        "watch birds",     "scratch"};
    void addDefaultIdeas();

  public:
    Cat();
    Cat(const Cat &copy);
    ~Cat();

    Cat               &operator=(const Cat &copy);

    const std::string &getIdea(unsigned int i) const;
    void               setIdea(const std::string &Idea, unsigned int i);

    void               makeSound() const;
};

#endif
