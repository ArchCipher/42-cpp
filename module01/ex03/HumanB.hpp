#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    string  _name;
    Weapon *_weapon;

  public:
    HumanB(const string &name);
    void setWeapon(Weapon &weapon);
    void attack();
};

#endif
