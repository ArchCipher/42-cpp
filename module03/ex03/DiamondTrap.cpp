#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string Name)
    : ClapTrap(Name + "_clap_name"), ScavTrap(), FragTrap()
{
    name = Name;
    std::cout << "DiamondTrap " << name << " was created\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
        name = copy.name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " was destroyed\n";
}

const std::string &DiamondTrap::getName() const
{
    return (name);
}

void DiamondTrap::setName(std::string Name)
{
    std::cout << "DiamondTrap setName : '" << name << "' was renamed to '"
              << Name << "'.\n";
    name = Name;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is " << name
              << " and my ClapTrap name is " << ClapTrap::name << "\n";
}
