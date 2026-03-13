#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    string  name;
    Weapon *weapon;

  public:
    HumanB(const string &name);
    void setWeapon(Weapon &my_weapon);
    void attack();
};

#endif
