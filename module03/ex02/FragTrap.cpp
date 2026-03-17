#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " was destroyed\n";
}

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name, FRAG_HIT_PTS, FRAG_ENERGY_PTS, FRAG_DAMAGE)
{
    std::cout << "FragTrap " << name << " was created\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
        std::cout << "FragTrap assignment operator called\n";
    }
    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " sending a positive highFive!\n";
}
