#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/*
Abstract class is a class that has atleast one pure virtual function.
Abstract classes can never be instantiated
Pure virtual function is a function that must be implemented in its derived class.

https://www.youtube.com/watch?v=T8f4ajtFU9g
https://www.youtube.com/watch?v=FGToBKDO8Zc

void               makeSound() const override;
// prevents child class from overriding this any further
void               makeSound() const final override;
// marking a class as final prevents inheritance from it
class DiamondTrap final
*/

#define MAX 10

void test_brain();
void test_wrong();

int  main()
{
	// Animal *animal = new Animal();
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
        std::cout << cats_and_dogs[i]->getType() << " : ";
        cats_and_dogs[i]->makeSound();
        delete cats_and_dogs[i];
    }
    // std::cout << "-----------------\n";
    // test_brain();
    // std::cout << "-----------------\n";
    // test_wrong();
    return 0;
}

void test_brain()
{
    srand((unsigned)time(0));
    Cat cat;
    Cat kitten(cat);
    Cat x;
    std::cout << cat.getType() << " " << cat.getIdea(0) << "\n"
              << kitten.getType() << " " << kitten.getIdea(0) << "\n"
              << x.getType() << " " << x.getIdea(0) << "\n";
    x = kitten;
    std::cout << x.getType() << " " << x.getIdea(0) << "\n";
}

void test_wrong()
{
    const WrongAnimal *wrongmeta = new WrongAnimal();
    const WrongAnimal *wrongi = new WrongCat();
    std::cout << wrongi->getType() << " " << std::endl;
    wrongi->makeSound();
    wrongmeta->makeSound();
    delete wrongmeta;
    delete wrongi;
}
