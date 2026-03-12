#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_MATERIA 4

class Character: public ICharacter
{
	std::string name;
	AMateria *materia[MAX_MATERIA];
	unsigned int index = 0;

	public:
	~Character();
	Character(std::string const & Name);
	Character(const Character &copy);
	Character &operator=(const Character &copy);

	std::string const &getName() const override;
	void equip(AMateria* m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter& target) override;
};

#endif
