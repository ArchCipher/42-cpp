#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#define FRAG_HIT_PTS 100
#define FRAG_ENERGY_PTS 100
#define FRAG_DAMAGE 30

class FragTrap : virtual public ClapTrap
{
  public:
    ~FragTrap(void);
    FragTrap(void);
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &copy);
    FragTrap &operator=(const FragTrap &copy);

    void      highFivesGuys(void);
};

#endif
