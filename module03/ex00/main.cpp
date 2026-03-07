#include "ClapTrap.hpp"

using std::cout;

void print(ClapTrap &trap);

int  main(void)
{
    ClapTrap trap1("trap1");
    print(trap1);

    trap1.attack("X");
    print(trap1);
    trap1.takeDamage(4);
    print(trap1);
    trap1.takeDamage(4);
    print(trap1);
    trap1.takeDamage(4);
    trap1.takeDamage(4);
    print(trap1);
    trap1.beRepaired(5);
    print(trap1);
    trap1.takeDamage(5);
    print(trap1);
    for (int i = 0; i < 9; i++)
        trap1.attack("X");
    trap1.beRepaired(5);
}

void print(ClapTrap &trap)
{
    cout << trap.getName() << " has " << trap.getHitPoints() << " hit_points, "
         << trap.getEnergyPoints() << " energy_points, "
         << trap.getAttackDamage() << " attack_damage\n\n";
}
