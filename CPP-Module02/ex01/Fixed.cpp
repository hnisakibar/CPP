/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 00:48:41 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/16 02:10:43 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const int integerValue)
{
	std::cout << "Int constructor called" << '\n';
	_rawBits = integerValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << '\n';
	_rawBits = (int)(roundf(floatValue * (1 << _fractionalBits)));
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
		_rawBits = other._rawBits;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << '\n';
}

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(_rawBits) / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
