#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name), _weapon(0)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (_weapon == 0)
	{
		std::cout << _name << " has no weapon." << '\n';
		return ;
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
}
