#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : hit_points(10), energy_points(10), attack_damage(0)
{
}

ClapTrap::ClapTrap(std::string Name) : ClapTrap()
{
    name = Name;
    std::cout << "ClapTrap " << name << " was created\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) : ClapTrap(copy.name)
{
    std::cout << "ClapTrap copy constructor called\n";
    hit_points = copy.hit_points;
    energy_points = copy.energy_points;
    attack_damage = copy.attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap assignment operator called\n";
    if (this != &copy)
    {
        name = copy.name;
        hit_points = copy.hit_points;
        energy_points = copy.energy_points;
        attack_damage = copy.attack_damage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " was destroyed\n";
}

const std::string &ClapTrap::getName() const
{
    return (name);
}

int ClapTrap::getHitPoints() const
{
    return (hit_points);
}

int ClapTrap::getEnergyPoints() const
{
    return (energy_points);
}

int ClapTrap::getAttackDamage() const
{
    return (attack_damage);
}

void ClapTrap::setName(std::string Name)
{
    std::cout << "setName : '" << name << "' was renamed to '" << Name
              << "'.\n";
    name = Name;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << name;
    if (!energy_points)
    {
        std::cout << " cannot attack. No energy_points left.\n";
        return;
    }
    energy_points--;
    std::cout << " attacks " << target << ", causing " << attack_damage
              << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name;
    if (!hit_points)
    {
        std::cout << " cannot take damage. No hit_points left.\n";
        return;
    }
    if (hit_points < amount)
    {
        std::cout << " takes damage losing " << hit_points << " hit_points.\n";
        hit_points = 0;
        return;
    }
    std::cout << " takes damage losing " << amount << " hit_points.\n";
    hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << name;
    if (!energy_points)
    {
        std::cout << " cannot regain hit_points. No energy_points left.\n";
        return;
    }
    energy_points--;
    hit_points += amount;
    std::cout << " regains " << amount << " hit_points!\n";
}
