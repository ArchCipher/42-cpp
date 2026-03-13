#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
  public:
    ~FragTrap(void);
    FragTrap(void);
    FragTrap(const std::string &name);

    void highFivesGuys(void);
};

#endif
