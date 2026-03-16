/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 03:18:50 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/16 03:20:13 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	base("Base");
	ScavTrap	guard("Guardian");

	base.attack("dummy");
	guard.attack("intruder");
	guard.guardGate();
	guard.takeDamage(42);
	guard.beRepaired(10);
	return (0);
}
