#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test_wrong_animal();
void test_copy();

int  main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " \n";
    std::cout << i->getType() << " \n";
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete i;
    delete j;
    delete meta;
    std::cout << "-----------------\n";
    test_wrong_animal();
    // std::cout << "-----------------\n";
    // test_copy();
    return 0;
}

void test_wrong_animal()
{
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();
    std::cout << i->getType() << " \n";
    i->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
}

void test_copy()
{
    Cat        cat;
    const Cat &cat2(cat);
    Cat        cat3;
    cat3 = cat2;
}
