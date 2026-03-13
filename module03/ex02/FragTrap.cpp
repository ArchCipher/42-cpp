#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " was destroyed\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " was created\n";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " sending a positive highFive!\n";
}
