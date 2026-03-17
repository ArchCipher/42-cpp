#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define SCAV_HIT_PTS 100
#define SCAV_ENERGY_PTS 50
#define SCAV_DAMAGE 20

class ScavTrap : virtual public ClapTrap
{
  public:
    ~ScavTrap(void);
    ScavTrap(void);
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &copy);
    ScavTrap &operator=(const ScavTrap &copy);

    void      attack(const std::string &target);
    void      guardGate();
};

#endif
