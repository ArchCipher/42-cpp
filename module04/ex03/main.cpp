#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

#include <iostream>

void test_character_copy(ICharacter *rhs);

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// create unknown material
	tmp = src->createMateria("none");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);// should do nothing
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob); // should do nothing
	test_character_copy(me);
	delete bob;
	delete me;
	delete src;
	return 0;
}

void test_character_copy(ICharacter *rhs)
{
	std::cout << "----------test for Character copy--------\n";
	ICharacter* copy = new Character(*(Character*)rhs);
	ICharacter* jim = new Character("jim");
	copy->use(0, *jim);
	copy->use(1, *jim);
	copy->use(2, *jim);
	copy->use(3, *jim);
	copy->use(4, *jim);
	delete copy;
	delete jim;
	std::cout << "----------end test for Character copy--------\n";
}
