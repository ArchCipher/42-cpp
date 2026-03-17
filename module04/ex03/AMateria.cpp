#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &copy) : type(copy.type) {}

AMateria &AMateria::operator=(const AMateria &copy)
{
    if (this != &copy)
        type = copy.type;
    return (*this);
}

std::string const &AMateria::getType() const
{
    return (type);
}
