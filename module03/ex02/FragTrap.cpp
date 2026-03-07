#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    std::cout << "FragTrap " << name << " was created\n";
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " was destroyed\n";
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " sending a positive highFive!\n";
}
