#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define DOG_IDEAS 10

class Dog : public Animal
{
    Brain *brain;

    void   addDefaultIdeas();

  public:
    ~Dog();
    Dog();
    Dog(const Dog &copy);
    Dog               &operator=(const Dog &copy);

    const std::string &getIdea(unsigned int i) const;
    void               setIdea(const std::string &idea, unsigned int i);

    void               makeSound() const; // override
};

#endif
