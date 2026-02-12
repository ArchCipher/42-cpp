#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

using std::string;

class Zombie
{
    string name;

public:
    ~Zombie();
    void setname(const string &_name);
    void announce( void );
};

Zombie* zombieHorde( int N, string name );

#endif
