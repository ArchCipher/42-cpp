#include "Zombie.hpp"

int main()
{
    Zombie *one;

    one = newZombie("Zombie1");
    one->announce();
    delete (one);
    randomChump("Zombie2");
}
