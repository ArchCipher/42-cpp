#include "Zombie.hpp"

Zombie* zombieHorde( int N, string name )
{
    Zombie *horde;

    horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        horde[i].setname(name);
    return (horde);
}