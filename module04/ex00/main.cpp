#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test_wrong();

// void test_copy();

int  main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete i;
    delete j;
    delete meta;
    std::cout << "-----------------\n";
    test_wrong();
    // std::cout << "-----------------\n";
    // test_copy();
    return 0;
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

void test_copy()
{
    Cat cat;
    Cat cat2(cat);
    Cat cat3;
    cat3 = cat;
}
