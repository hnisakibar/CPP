/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 03:51:00 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/16 03:51:01 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scav("Gatekeeper");
	FragTrap	frag("HighFiveBot");

	scav.attack("enemy");
	scav.guardGate();
	frag.attack("enemy");
	frag.highFivesGuys();
	frag.takeDamage(70);
	frag.beRepaired(20);
	return (0);
}

