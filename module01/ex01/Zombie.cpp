#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std:: cout << name << ": Destructed\n";
}

void Zombie::setname(const string &_name)
{
    name = _name;
}
