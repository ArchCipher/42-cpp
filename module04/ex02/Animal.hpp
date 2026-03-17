#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
  protected:
    std::string type;

  public:
    virtual ~Animal() {}

    Animal() {}

    Animal(const std::string &type);
    Animal(const Animal &copy);
    Animal            &operator=(const Animal &copy);

    void               setType(const std::string &my_type);
    const std::string &getType() const;

    // pure virtual function - no implementation, virtual and = 0
    virtual void       makeSound() const = 0;
};

#endif
