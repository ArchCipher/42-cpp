#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
  protected:
    std::string type;

  public:
    virtual ~Animal() = 0;
    Animal();
    Animal(std::string Type);
    Animal(const Animal &copy);
    Animal            &operator=(const Animal &copy);

    void               setType(std::string Type);
    const std::string &getType() const;

	// pure virtual function - no implementation, virtual and = 0
    virtual void       makeSound() const = 0;
};

#endif
