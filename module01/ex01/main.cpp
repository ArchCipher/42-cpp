#include "Zombie.hpp"

int main()
{
    const int horde_size = 10;
    Zombie   *horde = zombieHorde(horde_size, "ZombieHorde");

    for (int i = 0; i < horde_size; i++)
        horde[i].announce();
    delete[] (horde);
}
