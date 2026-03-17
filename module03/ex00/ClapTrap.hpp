#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define CLAP_HIT_PTS 10
#define CLAP_ENERGY_PTS 10

class ClapTrap
{
    std::string  name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

  public:
    ~ClapTrap(void);
    ClapTrap(void);
    ClapTrap(const std::string &my_name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap          &operator=(const ClapTrap &copy);

    const std::string &getName() const;
    unsigned int       getHitPoints() const;
    unsigned int       getEnergyPoints() const;
    unsigned int       getAttackDamage() const;
    void               setName(const std::string &my_name);

    void               attack(const std::string &target);
    void               takeDamage(unsigned int amount);
    void               beRepaired(unsigned int amount);
};

#endif
