#include "ScavTrap.hpp"

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " was destroyed\n";
}

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name, SCAV_HIT_PTS, SCAV_ENERGY_PTS, SCAV_DAMAGE)
{
    std::cout << "ScavTrap " << name << " was created\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
        std::cout << "ScavTrap assignment operator called\n";
    }
    return (*this);
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
