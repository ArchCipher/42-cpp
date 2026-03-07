#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called\n";
    energy_points = 50;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    std::cout << "ScavTrap " << name << " was created\n";
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " was destroyed\n";
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << name;
    if (!energy_points)
    {
        std::cout << " cannot attack. No energy_points left.\n";
        return;
    }
    energy_points--;
    std::cout << " attacks " << target << ", causing " << attack_damage
              << " points of damage!\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}
