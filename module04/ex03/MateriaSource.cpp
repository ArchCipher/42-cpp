#include "MateriaSource.hpp"
#include <iostream>
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < index; i++)
		delete (materia[i]);
	std::cout << "MateriaSource destructor\n";
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (index < MAX_MATERIA)
		materia[index++] = m;
}

#include <iostream>
AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < index; i++)
		if (materia[i]->getType() == type)
		{
			return (materia[i]->clone());
		}
	return (NULL);
}
