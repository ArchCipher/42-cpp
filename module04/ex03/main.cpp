#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <climits>
#include <iostream>

void test_invalid_input();
void test_inventory_full();
void test_equip_unequip();
void test_create_materia_ownership();
void test_create_materia_string();
void test_materia_copy();
void test_materia_assignment();
void test_character_copy();
void test_character_assignment();

int  main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria   *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    test_invalid_input();
    test_inventory_full();
    test_equip_unequip();
    test_create_materia_ownership();
    test_create_materia_string();
    test_materia_copy();
    test_materia_assignment();
    test_character_copy();
    test_character_assignment();
    return 0;
}

void test_invalid_input()
{
    std::cout << "\n--- test null or invalid input/index (no crash) ---\n";
    IMateriaSource *src = new MateriaSource();
    ICharacter     *me = new Character("me");
    AMateria *tmp = src->createMateria("ice"); // create not yet learnt materia
    me->equip(tmp);                            // equip NULL
    src->learnMateria(NULL);                   // learn NULL
    tmp = src->createMateria("unknown");       // create unknown materia
    me->equip(tmp);                            // equip NULL

    // unequip invalid index
    me->unequip(0);
    me->unequip(INT_MIN);
    me->unequip(INT_MAX);

    // use invalid index
    me->use(-1, *me);
    me->use(INT_MAX, *me);
    me->use(INT_MIN, *me);
    delete me;
    delete src;
}

void test_inventory_full()
{
    std::cout << "\n--- test inventory full - learn 5th materia, equip 5th "
                 "materia and use index 0-4 ---\n";
    IMateriaSource *src = new MateriaSource();
    ICharacter     *me = new Character("me");
    AMateria       *tmp = NULL;

    for (int i = 0; i < MAX_MATERIA; i++) // learn and eqip 4 materia
    {
        src->learnMateria(new Ice());
        tmp = src->createMateria("ice");
        me->equip(tmp);
    }
    src->learnMateria(new Cure()); // learn 5th materia
    tmp = src->createMateria("cure");
    me->equip(tmp); // equip 5th materia

    ICharacter *bob = new Character("bob");
    for (int i = 0; i <= MAX_MATERIA;
         i++)             // check index 4(out of range) as well
        me->use(i, *bob); // should print 4 slots
    delete bob;
    delete me;
    delete src;
}

void test_equip_unequip()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n--- equip same materia pointer twice ---\n";
    ICharacter *me = new Character("me");
    AMateria   *tmp = src->createMateria("ice");
    me->equip(tmp);
    me->equip(tmp);
    for (int i = 1; i < MAX_MATERIA; i++)
    {
        tmp = src->createMateria("ice");
        me->equip(tmp);
    }

    std::cout << "\n--- equip ice (prints ice), unequip and equip cure (prints "
                 "cure) ---\n";
    ICharacter *bob = new Character("bob");
    me->use(0, *bob); // should print ice
    std::cout << "\n";
    me->unequip(0);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(0, *bob); // should print cure
    delete bob;
    delete me;
    delete src;
}

void test_create_materia_ownership()
{
    std::cout << "\n--- test createMateria ownership (no crash) ---\n";
    MateriaSource src;
    src.learnMateria(new Ice());
    AMateria *tmp = src.createMateria("ice");
    delete tmp; // test if caller allowed to delete created materia
}

/*
    create_materia type is case-sensitive
    only accepts "ice" or "cure"
*/
void test_create_materia_string()
{
    std::cout << "\n--- test createMateria type string (case-sensitive) ---\n";
    MateriaSource src;
    src.learnMateria(new Ice());
    std::string type_string[3] = {"ice", "Ice", "ICE"};
    AMateria   *m = NULL;
    for (int i = 0; i < 3; i++)
    {
        m = src.createMateria(type_string[i]);
        if (m)
        {
            std::cout << type_string[i] << ": ok\n";
            delete m;
            m = NULL;
        }
    }
}

void test_materia_copy()
{
    std::cout
        << "\n--- test MateriaSource copy (no crash, should print ice) ---\n";
    MateriaSource src;
    src.learnMateria(new Ice());
    MateriaSource copy(src);                       // copy MateriaSource
    AMateria     *tmp = copy.createMateria("ice"); // create "ice" using copy
    ICharacter   *me = new Character("me");
    ICharacter   *bob = new Character("bob");
    me->equip(tmp);
    me->use(0, *bob);
    delete bob;
    delete me;
}

void test_materia_assignment()
{
    std::cout << "\n--- test MateriaSource assignment (no crash, should print "
                 "ice and then cure) ---\n";
    MateriaSource a;
    a.learnMateria(new Ice());
    a.learnMateria(new Cure());
    MateriaSource b = a; // assign MateriaSource
    MateriaSource c = a; // assign MateriaSource
    ICharacter   *me = new Character("me");
    ICharacter   *bob = new Character("bob");
    AMateria     *tmp = b.createMateria("ice"); // create "ice" using b
    me->equip(tmp);
    me->use(0, *bob);              // should print ice
    tmp = c.createMateria("cure"); // create "cure" using c
    me->equip(tmp);
    me->use(1, *bob); // should print cure
    delete bob;
    delete me;
}

void test_character_copy()
{
    std::cout << "\n--- test Character copy (no crash, should print ice and "
                 "then cure) ---\n";
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    Character me("me");
    AMateria *tmp = src->createMateria("ice");
    me.equip(tmp);
    tmp = src->createMateria("cure");
    me.equip(tmp);
    Character bob("bob");
    Character copy(me); // copy character
    for (int i = 0; i < MAX_MATERIA; i++)
        copy.use(i, bob);
    delete src;
}

void test_character_assignment()
{
    std::cout << "\n--- test Character copy (no crash, should print ice and "
                 "then cure) ---\n";
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    Character me("me");
    AMateria *tmp = src->createMateria("ice");
    me.equip(tmp);
    tmp = src->createMateria("cure");
    me.equip(tmp);
    Character bob("bob");
    Character copy = me; // copy character
    for (int i = 0; i < MAX_MATERIA; i++)
        copy.use(i, bob);
    delete src;
}
