#include "Zombie.hpp"

int	main(void)
{
	int		count;
	Zombie	*horde;

	count = 5;
	horde = zombieHorde(count, "Zombie");
	if (horde == 0)
		return (1);
	for (int i = 0; i < count; ++i)
		horde[i].announce();
	delete[] horde;
	return (0);
}
