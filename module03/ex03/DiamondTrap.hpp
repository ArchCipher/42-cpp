#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    std::string name;

  public:
    DiamondTrap(std::string Name);
    DiamondTrap &operator=(const DiamondTrap &copy);
    ~DiamondTrap(void);

    const std::string &getName() const;
    void               setName(std::string Name);
    void               whoAmI();
};

#endif
