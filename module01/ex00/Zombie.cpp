#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " destructed\n";
}

Zombie::Zombie(const string &my_name) : name(my_name)
{
    std::cout << "Zombie " << name << " created\n";
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
