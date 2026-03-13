#include "HumanB.hpp"

HumanB::HumanB(const string &name) : name(name), weapon(0) {}

void HumanB::setWeapon(Weapon &my_weapon)
{
    weapon = &my_weapon;
}

void HumanB::attack()
{
    if (!weapon)
    {
        std::cout << name << " has no weapon\n";
        return;
    }
    std::cout << name << " attacks with their " << weapon->getType() << "\n";
}
