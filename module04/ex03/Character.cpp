#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

Character::~Character()
{
    for (int i = 0; i < MAX_MATERIA; i++)
        delete materia[i];
    for (int i = 0; i < MAX_UNEQUIP; i++)
        delete floorMateria[i];
}

Character::Character(const std::string &name)
    : name(name), materia(), floorMateria()
{
}

Character::Character(const Character &copy)
    : name(copy.name), materia(), floorMateria()
{
    for (int i = 0; i < MAX_MATERIA; i++)
    {
        if (copy.materia[i])
            materia[i] = copy.materia[i]->clone();
    }
    for (int i = 0; i < MAX_UNEQUIP; i++)
    {
        if (copy.floorMateria[i])
            floorMateria[i] = copy.floorMateria[i]->clone();
    }
}

Character &Character::operator=(const Character &copy)
{
    if (this == &copy)
        return (*this);
    name = copy.name;
    for (int i = 0; i < MAX_UNEQUIP; i++)
    {
        if (floorMateria[i])
            delete (floorMateria[i]);
        floorMateria[i] = NULL;
        if (copy.floorMateria[i])
            floorMateria[i] = copy.floorMateria[i]->clone();
    }
    for (int i = 0; i < MAX_UNEQUIP; i++)
    {
        if (floorMateria[i])
            delete (floorMateria[i]);
        floorMateria[i] = NULL;
        if (copy.floorMateria[i])
            floorMateria[i] = copy.floorMateria[i]->clone();
    }
    return (*this);
}

const std::string &Character::getName() const
{
    return (name);
}

bool Character::inInventory(AMateria *m)
{
    for (int i = 0; i < MAX_MATERIA; i++)
    {
        if (materia[i] && materia[i] == m)
            return (true);
    }
    return (false);
}

void Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "No materia to add...\n";
        return;
    }
    if (inInventory(m))
    {
        std::cout << "Materia " << m->getType() << " already equipped...\n";
        return;
    }
    for (int i = 0; i < MAX_MATERIA; i++)
    {
        if (!materia[i])
        {
            materia[i] = m;
            return;
        }
    }
    std::cout << "Materia inventory full! Cannot equip new materia...\n";
    addFloorMateria(m);
}

bool Character::inFloorInventory(AMateria *m)
{
    for (int i = 0; i < MAX_UNEQUIP; i++)
    {
        if (floorMateria[i] && floorMateria[i] == m)
            return (true);
    }
    return (false);
}

bool Character::addFloorMateria(AMateria *m)
{
    if (inFloorInventory(m))
        return (true);
    for (int i = 0; i < MAX_UNEQUIP; i++)
    {
        if (!floorMateria[i])
        {
            floorMateria[i] = m;
            return (true);
        }
    }
    return (false);
}

void Character::clearFloorMateria()
{
    for (int i = 0; i < MAX_UNEQUIP; i++)
    {
        delete floorMateria[i];
        floorMateria[i] = NULL;
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= MAX_MATERIA || !materia[idx])
        return;
    if (inFloorInventory(materia[idx]))
    {
        std::cout << "Materia " << materia[idx]->getType()
                  << " already unequipped...\n";
        return;
    }
    if (addFloorMateria(materia[idx]))
    {
        materia[idx] = NULL;
        return;
    }
    std::cout << "Unequipped (floor) materia inventory full! Clearing floor "
                 "materia inventory...\n";
    clearFloorMateria();
    unequip(idx);
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= MAX_MATERIA)
        return;
    if (materia[idx])
        materia[idx]->use(target);
}
