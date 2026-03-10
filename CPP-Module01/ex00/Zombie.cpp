#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
}

Zombie::Zombie(const std::string &name) : _name(name)
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

Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}

void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();
}