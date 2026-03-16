/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 03:13:31 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/16 03:13:32 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	alpha("Alpha");
	ClapTrap	beta("Beta");

	alpha.attack("Beta");
	beta.takeDamage(3);
	beta.beRepaired(2);
	beta.takeDamage(20);
	beta.attack("Alpha");
	return (0);
}
