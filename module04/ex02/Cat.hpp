#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define CAT_IDEAS 10

class Cat : public Animal
{
    Brain *brain;

    void   addDefaultIdeas();

  public:
    ~Cat();
    Cat();
    Cat(const Cat &copy);
    Cat               &operator=(const Cat &copy);

    const std::string &getIdea(unsigned int i) const;
    void               setIdea(const std::string &idea, unsigned int i);

    void               makeSound() const; // override
};

#endif
