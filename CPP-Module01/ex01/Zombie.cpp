#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
	std::cout << _name << " is destroyed." << '\n';
}

void	Zombie::setName(const std::string &name)
{
	_name = name;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << '\n';
}
