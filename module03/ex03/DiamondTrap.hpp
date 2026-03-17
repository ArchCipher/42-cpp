#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    std::string name;

  public:
    ~DiamondTrap(void);
    DiamondTrap(const std::string &my_name);
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap       &operator=(const DiamondTrap &copy);

    const std::string &getName() const;
    void               setName(const std::string &my_name);
    void               whoAmI();
};

#endif
