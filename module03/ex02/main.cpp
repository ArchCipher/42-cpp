#include "FragTrap.hpp"
#include "ScavTrap.hpp"

using std::cout;

void test_frag();
void test_scav();
void test_clap();
void print_status(ClapTrap &trap);

int  main(void)
{
    test_clap();
    test_scav();
    test_frag();
}

void test_frag()
{
    cout << "\n--- Frag tests ---\n\n";
    FragTrap trap4("trap4");
    print_status(trap4);

    trap4.attack("X");
    print_status(trap4);
    const unsigned int amount = 10;
    trap4.takeDamage(amount);
    print_status(trap4);
    trap4.beRepaired(amount);
    print_status(trap4);

    trap4.highFivesGuys();
}

void test_scav()
{
    cout << "\n--- Scav tests ---\n\n";
    ScavTrap trap1("trap1");
    print_status(trap1);

    trap1.attack("X");
    print_status(trap1);

    ScavTrap trap2(trap1);
    trap2.setName("trap2");
    print_status(trap2);

    const unsigned int amount = 5;
    trap1.takeDamage(amount);
    print_status(trap1);
    trap1.beRepaired(amount);
    print_status(trap1);

    ScavTrap trap3("trap3");
    print_status(trap3);
    trap3 = trap1;
    trap3.setName("trap3");
    print_status(trap3);

    trap3.guardGate();
}

void test_clap()
{
    cout << "--- Clap tests ---\n\n";
    ClapTrap trap1("trap1");
    print_status(trap1);

    const unsigned int amount = 4;
    trap1.attack("X");
    print_status(trap1);
    trap1.takeDamage(amount);
    print_status(trap1);
    trap1.beRepaired(amount);
    print_status(trap1);
}

void print_status(ClapTrap &trap)
{
    cout << "Trap " << trap.getName() << " has " << trap.getHitPoints()
         << " hit_points, " << trap.getEnergyPoints() << " energy_points, "
         << trap.getAttackDamage() << " attack_damage\n\n";
}
