#include "Zombie.hpp"

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(const string &_name) {
    name = _name;
}

Zombie::~Zombie() {
    std::cout << name << ": Destructed\n";
}
