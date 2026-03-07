#include "ScavTrap.hpp"

using std::cout;

void test_scav();
void test_clap();
void print(ClapTrap &trap);

int  main(void)
{
    cout << "ClapTrap tests\n\n";
    test_clap();
    cout << "----------------------\n"
         << "ScavTrap tests\n\n";
    test_scav();
}

void test_scav()
{
    ScavTrap trap1("trap1");
    print(trap1);

    trap1.attack("X");
    print(trap1);

    ScavTrap trap2(trap1);
    trap2.setName("trap2");
    print(trap2);

    trap1.takeDamage(5);
    print(trap1);
    trap1.beRepaired(5);
    print(trap1);

    ScavTrap trap3("trap3");
    print(trap3);
    trap3 = trap1;
    trap3.setName("trap3");
    print(trap3);

    trap3.guardGate();
}

void test_clap()
{
    ClapTrap trap1("trap1");
    print(trap1);

    trap1.attack("X");
    print(trap1);
    trap1.takeDamage(4);
    print(trap1);
    trap1.beRepaired(4);
    print(trap1);
}

void print(ClapTrap &trap)
{
    cout << "Trap " << trap.getName() << " has " << trap.getHitPoints()
         << " hit_points, " << trap.getEnergyPoints() << " energy_points, "
         << trap.getAttackDamage() << " attack_damage\n\n";
}
