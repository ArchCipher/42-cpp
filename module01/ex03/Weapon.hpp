#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

using std::string;

class Weapon
{
    string type;

  public:
    Weapon(const string &type);

    const string &getType();
    void          setType(const string &my_type);
};

#endif
