#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
  protected:
    std::string type;

  public:
    ~WrongAnimal();
    WrongAnimal();
    WrongAnimal(const std::string &type);
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal       &operator=(const WrongAnimal &copy);

    void               setType(const std::string &my_type);
    const std::string &getType() const;

    void               makeSound() const;
};

#endif
