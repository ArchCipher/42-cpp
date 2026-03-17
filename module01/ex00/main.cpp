#include "Zombie.hpp"

int main()
{
    Zombie *one = newZombie("heap_zombie"); // allocates on heap
    one->announce();
    delete (one);

    randomChump("stack_zombie"); // allocates on stack
}
