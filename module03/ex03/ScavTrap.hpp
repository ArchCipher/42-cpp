#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
  public:
    ~ScavTrap(void);
    ScavTrap(void);
    ScavTrap(const std::string &name);

    void attack(const std::string &target);
    void guardGate();
};

#endif
