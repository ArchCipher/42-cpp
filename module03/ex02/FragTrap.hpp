#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
  public:
    FragTrap(std::string Name);
    ~FragTrap(void);

    void highFivesGuys(void);
};

#endif
