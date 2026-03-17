#include "ClapTrap.hpp"

using std::cout;

void print_status(ClapTrap &trap);

int  main(void)
{
    ClapTrap trap1("trap1");
    print_status(trap1);

    trap1.attack("X");
    print_status(trap1);
    std::cout << "--- take 4 damage until no hit points ---\n";
    const unsigned int amount = 4;
    for (unsigned int i = 0; i < amount; i++)
    {
        trap1.takeDamage(amount);
        print_status(trap1);
    }
    std::cout << "--- repairs 4 and take 4 damage ---\n";
    trap1.beRepaired(amount);
    print_status(trap1);
    trap1.takeDamage(amount);
    print_status(trap1);
    std::cout << "--- attack until no energy points ---\n";
    unsigned int energy_point_left = trap1.getEnergyPoints();
    for (unsigned int i = 0; i <= energy_point_left; i++)
        trap1.attack("X");
    trap1.beRepaired(amount);
}

void print_status(ClapTrap &trap)
{
    cout << trap.getName() << " has " << trap.getHitPoints() << " hit_points, "
         << trap.getEnergyPoints() << " energy_points, "
         << trap.getAttackDamage() << " attack_damage\n\n";
}
