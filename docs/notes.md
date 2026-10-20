# CPP

clang-tidy
```sh
for f in main.cpp Zombie.cpp newZombie.cpp randomChump.cpp; do
  clang-tidy "$f" -- -std=c++98 -Wall -Werror -Wextra -I.
done
```

OOP is a type of programming paradigm.
Programming paradigms are a way of solving a problem. They are distinct approaches, methodologies, or styles of coding that define how a program is structured and implemented, influencing how developers solve problems.
There are several types of programming paradigm and OOP is one of them.

**Class:** used to represent real life objects.
It can have 2 parts:
    Attributes
    behavior(class method)

**Constructor:** invoked each time a class is created
If no constructor is defined, constructor is default constructor
constructor has 3 properties: no return type, same name as the class, should be public

4 pillars or main concepts of OOP: 
**Encapsulation:** make attributes private and use public methods(getters and setters) to modify the attributes/properties
**Abstraction:**

```cpp
class AbstractEmployee {
    virtual void AskForPromotion() = 0;
}
```

Now, `AbstractEmployee` is an abstract class and the method `AskForPromotion` is a Pure virtual function/ abstract function

```cpp
How can class sign the contract AbstractEmployee
class Employee: AbstractEmployee{

};
```

**Inheritance:**
Base class and derived class. derived class/child class inherits all properties(attributes and methods) of its base class/parent class. 

**Polymorphism:**
When parent class and derived class have the same method, if parent class method is virtual, the child will be executed in case child has the same method, only if not then the patent will be executed.

**Interface:** boundary or point of interaction between two systems, components, or people that lets them communicate or work together without needing to know each other’s internal details.
