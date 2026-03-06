#include "Weapon.hpp"

Weapon::Weapon(const string &type) {
    _type = type;
}

const string &Weapon::getType() {
    return (_type);
}

void Weapon::setType(const string &type) {
    _type = type;
}
