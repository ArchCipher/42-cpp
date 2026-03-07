#include "Zombie.hpp"

int main()
{
    Zombie *horde;
    int     horde_size;

    horde_size = 10;
    horde = zombieHorde(horde_size, "ZombieHorde");
    for (int i = 0; i < horde_size; i++)
        horde[i].announce();
    delete[] (horde);
}