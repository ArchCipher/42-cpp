#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
  public:
    FragTrap(void);
    FragTrap(std::string Name);
    ~FragTrap(void);

    void highFivesGuys(void);
};

#endif
