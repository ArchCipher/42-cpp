#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " was destroyed\n";
}

DiamondTrap::DiamondTrap(const std::string &my_name)
    : ClapTrap(my_name + "_clap_name", FRAG_HIT_PTS, SCAV_ENERGY_PTS,
               FRAG_DAMAGE),
      name(my_name)
{
    std::cout << "DiamondTrap " << name << " was created\n";
}

// works even without specifying copy constructor but not assignment operator
DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), name(copy.name)
{
    std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
        name = copy.name;
        std::cout << "DiamondTrap assignment operator called\n";
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
