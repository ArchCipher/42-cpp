#ifndef AMATERIA_SOURCE_HPP
#define AMATERIA_SOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MAX_MATERIA 4

class MateriaSource: public IMateriaSource
{
	AMateria *materia[MAX_MATERIA];
	unsigned int index = 0;
	public:
	~MateriaSource();
	void learnMateria(AMateria *m) override;
	AMateria* createMateria(std::string const & type) override;
};

#endif
