#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
  protected:
    std::string name;
    int         hit_points;
    int         energy_points;
    int         attack_damage;

  public:
    ClapTrap(void);
    ClapTrap(std::string Name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap &operator=(const ClapTrap &copy);
    ~ClapTrap(void);

    const std::string &getName() const;
    int                getHitPoints() const;
    int                getEnergyPoints() const;
    int                getAttackDamage() const;
    void               setName(std::string Name);

    void               attack(const std::string &target);
    void               takeDamage(unsigned int amount);
    void               beRepaired(unsigned int amount);
};

#endif
