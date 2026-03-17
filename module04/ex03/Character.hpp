#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class ICharacter;

#define MAX_MATERIA 4
#define MAX_UNEQUIP 20

class Character : public ICharacter
{
    std::string name;
    AMateria   *materia[MAX_MATERIA];
    AMateria   *floorMateria[MAX_UNEQUIP];

    void        copyMateria(const Character &copy);
    bool        addFloorMateria(AMateria *m);
    void        clearFloorMateria();
    bool        inInventory(AMateria *m);
    bool        inFloorInventory(AMateria *m);

  public:
    virtual ~Character();
    Character(const std::string &name);
    Character(const Character &copy);
    Character         &operator=(const Character &copy);

    const std::string &getName() const;                  // final
    void               equip(AMateria *m);               // final
    void               unequip(int idx);                 // final
    void               use(int idx, ICharacter &target); // final
};

#endif
