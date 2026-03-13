#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " was destroyed\n";
}

DiamondTrap::DiamondTrap(const std::string &my_name)
    : ClapTrap(my_name + "_clap_name")
{
    name = my_name;
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

const std::string &DiamondTrap::getName() const
{
    return (name);
}

void DiamondTrap::setName(const std::string &my_name)
{
    std::cout << "DiamondTrap setName : '" << name << "' was renamed to '"
              << my_name << "'.\n";
    name = my_name;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is " << name
              << " and my ClapTrap name is " << ClapTrap::name << "\n";
}
