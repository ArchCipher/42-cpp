#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
public:
	~Cure();
	Cure();
	Cure(const Cure &copy);
	AMateria* clone() const override;
	void use(ICharacter& target) final override;
};

#endif
