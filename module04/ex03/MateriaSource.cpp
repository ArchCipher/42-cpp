#include "MateriaSource.hpp"

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MAX_MATERIA; i++)
        delete (materia[i]);
}

MateriaSource::MateriaSource() : materia(), idx(0) {}

MateriaSource::MateriaSource(const MateriaSource &copy)
    : materia(), idx(copy.idx)
{
    for (int i = 0; i < MAX_MATERIA; i++)
    {
        if (copy.materia[i])
            materia[i] = copy.materia[i]->clone();
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    if (this == &copy)
        return (*this);
    for (int i = 0; i < MAX_MATERIA; i++)
    {
        if (materia[i])
            delete (materia[i]);
        materia[i] = NULL;
        if (copy.materia[i])
            materia[i] = copy.materia[i]->clone();
    }
    idx = copy.idx;
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    if (idx == MAX_MATERIA)
        idx = 0;
    if (materia[idx])
    {
        std::cout << "MateriaSource full! Deleting " << materia[idx]->getType()
                  << " materia to learn " << m->getType() << " materia...\n";
        delete materia[idx];
    }
    materia[idx++] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < MAX_MATERIA; i++)
        if (materia[i] && materia[i]->getType() == type)
            return (materia[i]->clone());
    return (NULL);
}
