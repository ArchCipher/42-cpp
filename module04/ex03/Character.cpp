#include "Character.hpp"

Character::~Character()
{
	for (int i = 0; i < index; i++)
		delete (materia[i]);
	index = 0;
}

Character::Character(std::string const &Name): name(Name)
{
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character &Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < index; i++)
			delete (materia[i]);
		name = copy.name;
		index = copy.index;
		for (int i = 0; i < index; i++)
		{
			materia[i] = copy.materia[i]->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (name);
}
#include <iostream>
void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	if (index < MAX_MATERIA)
		materia[index++] = m->clone();
}
void Character::unequip(int idx)
{
	// The unequip() member function must NOT delete the Materia!
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < index)
		materia[idx]->use(target);
}
