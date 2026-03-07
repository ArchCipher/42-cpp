#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
  public:
    ScavTrap(std::string Name);
    ~ScavTrap(void);

    void attack(const std::string &target);
    void guardGate();
};

#endif
