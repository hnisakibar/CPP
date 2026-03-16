/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 03:53:22 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/16 03:53:23 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap	&operator=(const FragTrap &other);
	~FragTrap(void);

	void	attack(const std::string &target);
	void	highFivesGuys(void);
};

#endif

