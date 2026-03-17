#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/*
Abstract class is a class that has atleast one pure virtual function.
Abstract classes can never be instantiated
Pure virtual function is a function that must be implemented in its derived
class.

https://www.youtube.com/watch?v=T8f4ajtFU9g
https://www.youtube.com/watch?v=FGToBKDO8Zc

void               makeSound() const override;
// prevents child class from overriding this any further
void               makeSound() const final override;
// marking a class as final prevents inheritance from it
class DiamondTrap final
*/

#define MAX 10

void test_cat_copy();
void test_cat_assignment();
void test_wrong_animal();

int  main()
{
    // cannot instantiate Animal;
    // Animal *animal = new Animal();
    srand((unsigned)time(0));
    std::cout
        << "\n--- create an array of Animal objects (half cat, half dog) ---\n";
    const Animal *cats_and_dogs[MAX];
    for (int i = 0; i < MAX; i++)
    {
        if (i < MAX / 2)
            cats_and_dogs[i] = new Cat();
        else
            cats_and_dogs[i] = new Dog();
    }
    for (int i = 0; i < MAX; i++)
    {
        std::cout << cats_and_dogs[i]->getType() << ": ";
        cats_and_dogs[i]->makeSound();
        delete cats_and_dogs[i];
    }
    srand((unsigned)time(0));
    test_cat_copy();
    test_cat_assignment();
    // test_wrong_animal();
    return 0;
}

void test_cat_copy()
{
    std::cout << "\n--- test copy ---\n";
    const Cat cat;
    const Cat kitten(cat);
    std::cout << cat.getType() << " " << cat.getIdea(0) << "\n"
              << kitten.getType() << " " << kitten.getIdea(0) << "\n";
}

void test_cat_assignment()
{
    std::cout
        << "\n--- test assignment (before (both)/after (only copy)) ---\n";
    const Cat cat;
    Cat       x;
    std::cout << cat.getType() << " " << cat.getIdea(0) << "\n"
              << x.getType() << " " << x.getIdea(0) << "\n";
    x = cat;
    std::cout << x.getType() << " " << x.getIdea(0) << "\n";
}

void test_wrong_animal()
{
    std::cout << "\n--- test wrong animal---\n";
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();
    std::cout << i->getType() << " \n";
    i->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
}
