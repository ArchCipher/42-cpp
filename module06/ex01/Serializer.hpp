#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

/*
        class Serializer, which cannot be initialized by the user.

        uintptr_t serialize(Data* ptr);
                converts a pointer to the unsigned integer type uintptr_t.
        Data* deserialize(uintptr_t raw);
                converts an unsigned integer to a pointer to Data.
*/
class Serializer
{
    Serializer() {};
    Serializer(const Serializer &) {};
    Serializer &operator=(const Serializer &);

  public:
    virtual ~Serializer() {};
    static uintptr_t serialize(Data *ptr);
    static Data     *deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &out, const Data &data);

#endif
