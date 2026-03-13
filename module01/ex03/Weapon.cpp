#include "Weapon.hpp"

Weapon::Weapon(const string &type) : type(type) {}

const string &Weapon::getType()
{
    return (type);
}

void Weapon::setType(const string &my_type)
{
    type = my_type;
}
