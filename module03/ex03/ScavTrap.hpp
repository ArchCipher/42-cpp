#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
  public:
    ScavTrap(void);
    ScavTrap(std::string Name);
    ~ScavTrap(void);

    void attack(const std::string &target);
    void guardGate();
};

#endif
