#include "ScavTrap.hpp"

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " was destroyed\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " was created\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << name;
    if (!energyPoints)
    {
        std::cout << " cannot attack. No energy_points left.\n";
        return;
    }
    energyPoints--;
    std::cout << " attacks " << target << ", causing " << attackDamage
              << " points of damage!\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}
