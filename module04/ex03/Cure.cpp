#include <iostream>
#include "Cure.hpp"

Cure::~Cure()
{
	std::cout << "Cure destructor\n";
}

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure constructor\n";
}

Cure::Cure(const Cure &copy): AMateria(copy)
{
	std::cout << "Cure copy constructor\n";
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
