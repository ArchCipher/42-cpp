#include "Serializer.hpp"
#include <iostream>

Serializer &Serializer::operator=(const Serializer &)
{
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
    return (reinterpret_cast<Data *>(raw));
}

std::ostream &operator<<(std::ostream &out, const Data &data)
{
    out << "char: '" << data.c << "'\n"
        << "int: " << data.i << '\n'
        << "float: " << data.f << "\n"
        << "double: " << data.d << "\n";
    return (out);
}
