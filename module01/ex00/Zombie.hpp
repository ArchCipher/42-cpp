#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

using std::string;

class Zombie
{
    string name;

  public:
    ~Zombie();
    Zombie(const string &my_name);

    void announce(void);
};

Zombie *newZombie(string name);   // NOLINT(readability-identifier-naming)
void    randomChump(string name); // NOLINT(readability-identifier-naming)

#endif
