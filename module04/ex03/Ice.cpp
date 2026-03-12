#include <iostream>
#include "Ice.hpp"

Ice::~Ice()
{
	std::cout << "Ice destructor\n";
}

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice constructor\n";
}

Ice::Ice(const Ice &copy): AMateria(copy)
{
	std::cout << "Ice copy constructor\n";
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
