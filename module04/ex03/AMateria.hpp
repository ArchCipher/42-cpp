#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
  protected:
    std::string type;

  public:
    virtual ~AMateria() {}

    AMateria(const std::string &type);
    AMateria(const AMateria &copy);
    AMateria          &operator=(const AMateria &copy);

    const std::string &getType() const;
    virtual AMateria  *clone() const = 0;

    virtual void       use(ICharacter &) = 0;
};

#endif
