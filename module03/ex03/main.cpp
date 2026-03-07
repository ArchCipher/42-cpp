#include "DiamondTrap.hpp"

using std::cout;

void test_clap();
void test_scav();
void test_frag();
void test_diamond();
void print(ClapTrap &trap);

int  main(void)
{
    cout << "ClapTrap tests\n\n";
    test_clap();
    cout << "----------------------\n"
         << "ScavTrap tests\n\n";
    test_scav();
    cout << "----------------------\n"
         << "FragTrap tests\n\n";
    test_frag();
    cout << "----------------------\n"
         << "DiamondTrap tests\n\n";
    test_diamond();
}

void test_diamond()
{
    DiamondTrap trap5("trap5");
    cout << "DiamondTrap " << trap5.getName() << " : ";
    print(trap5);

    trap5.attack("X");
    cout << "DiamondTrap " << trap5.getName() << " : ";
    print(trap5);

    DiamondTrap trap6(trap5);
    trap6.setName("trap6");
    cout << "DiamondTrap " << trap6.getName() << " : ";
    print(trap6);

    DiamondTrap trap7("trap7");
    cout << "DiamondTrap " << trap7.getName() << " : ";
    print(trap7);

    trap5.attack("X");
    trap5.whoAmI();

    trap7 = trap5;
    trap7.setName("trap7");
    cout << "DiamondTrap " << trap7.getName() << " : ";
    print(trap7);
}

void test_frag()
{
    FragTrap trap4("trap4");
    print(trap4);

    trap4.attack("X");
    print(trap4);
    trap4.takeDamage(10);
    print(trap4);
    trap4.beRepaired(10);
    print(trap4);

    trap4.highFivesGuys();
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
