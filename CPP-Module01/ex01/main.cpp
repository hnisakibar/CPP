/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:52:59 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/14 03:33:14 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		count;
	Zombie	*horde;

	count = 0;
	horde = zombieHorde(count, "Zombie");
	if (horde == 0)
		return (1);
	for (int i = 0; i < count; ++i)
		horde[i].announce();
	delete[] horde;
	return (0);
}
