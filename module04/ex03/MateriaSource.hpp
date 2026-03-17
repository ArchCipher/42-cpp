#ifndef AMATERIA_SOURCE_HPP
#define AMATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

#define MAX_MATERIA 4

class MateriaSource : public IMateriaSource
{
    AMateria *materia[MAX_MATERIA];
    int       idx;

  public:
    ~MateriaSource();
    MateriaSource();
    MateriaSource(const MateriaSource &copy);
    MateriaSource &operator=(const MateriaSource &copy);

    void           learnMateria(AMateria *m);              // final
    AMateria      *createMateria(std::string const &type); // final
};

#endif
