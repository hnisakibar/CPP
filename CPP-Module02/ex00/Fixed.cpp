/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:16:07 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/15 18:20:26 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << '\n';
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << '\n';
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << '\n';
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}
