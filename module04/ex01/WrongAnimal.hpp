#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
  protected:
    std::string type;

  public:
    WrongAnimal();
    WrongAnimal(std::string Type);
    WrongAnimal(const WrongAnimal &copy);
    ~WrongAnimal();

    WrongAnimal       &operator=(const WrongAnimal &copy);

    void               setType(std::string Type);
    const std::string &getType() const;

    void               makeSound() const;
};

#endif
