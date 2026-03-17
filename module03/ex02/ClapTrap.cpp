#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " was destroyed\n";
}

ClapTrap::ClapTrap(void)
    : hitPoints(CLAP_HIT_PTS), energyPoints(CLAP_ENERGY_PTS), attackDamage(0)
{
}

ClapTrap::ClapTrap(const std::string &my_name)
    : name(my_name), hitPoints(CLAP_HIT_PTS), energyPoints(CLAP_ENERGY_PTS),
      attackDamage(0)
{
    std::cout << "ClapTrap " << name << " was created\n";
}

ClapTrap::ClapTrap(const std::string &my_name, unsigned int hit_points,
                   unsigned int energy_points, unsigned int attack_damage)
    : name(my_name), hitPoints(hit_points), energyPoints(energy_points),
      attackDamage(attack_damage)
{
    std::cout << "ClapTrap " << name << " was created\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : name(copy.name), hitPoints(copy.hitPoints),
      energyPoints(copy.energyPoints), attackDamage(copy.attackDamage)
{
    std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap assignment operator called\n";
    if (this != &copy)
    {
        name = copy.name;
        hitPoints = copy.hitPoints;
        energyPoints = copy.energyPoints;
        attackDamage = copy.attackDamage;
    }
    return (*this);
}

const std::string &ClapTrap::getName() const
{
    return (name);
}

unsigned int ClapTrap::getHitPoints() const
{
    return (hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return (energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
    return (attackDamage);
}

void ClapTrap::setName(const std::string &my_name)
{
    std::cout << "setName : '" << name << "' was renamed to '" << my_name
              << "'.\n";
    name = my_name;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << name;
    if (!energyPoints)
    {
        std::cout << " cannot attack. No energy_points left.\n";
        return;
    }
    energyPoints--;
    std::cout << " attacks " << target << ", causing " << attackDamage
              << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name;
    if (!hitPoints)
    {
        std::cout << " cannot take damage. No hit_points left.\n";
        return;
    }
    if (hitPoints < amount)
    {
        std::cout << " takes damage losing " << hitPoints << " hit_points.\n";
        hitPoints = 0;
        return;
    }
    std::cout << " takes damage losing " << amount << " hit_points.\n";
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << name;
    if (!energyPoints)
    {
        std::cout << " cannot regain hit_points. No energy_points left.\n";
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << " regains " << amount << " hit_points!\n";
}
