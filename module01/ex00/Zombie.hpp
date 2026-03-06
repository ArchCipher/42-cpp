#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

using std::string;

class Zombie {
    string name;

  public:
    Zombie(const string &_name);
    ~Zombie();
    void announce(void);
};

Zombie *newZombie(string name);
void randomChump(string name);

#endif
