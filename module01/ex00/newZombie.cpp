#include "Zombie.hpp"

// use new and allocate on heap
Zombie *newZombie(string name) {
    Zombie *new_zombie;

    new_zombie = new Zombie(name);
    return (new_zombie);
}