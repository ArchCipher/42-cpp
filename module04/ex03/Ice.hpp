#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	~Ice();
	Ice();
	Ice(const Ice &copy);
	AMateria* clone() const override;
	void use(ICharacter& target) final override;
};

#endif
