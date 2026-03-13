#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << name << ": Destructed\n";
}

void Zombie::setname(const string &my_name)
{
    name = my_name;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
