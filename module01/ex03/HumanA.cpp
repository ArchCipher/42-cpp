#include "HumanA.hpp"

HumanA::HumanA(const string &name, Weapon &weapon):
            _name(name), _weapon(weapon)
{
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their "
            << _weapon.getType() << std::endl;
}
