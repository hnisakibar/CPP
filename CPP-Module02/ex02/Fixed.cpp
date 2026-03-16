/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:27:38 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/16 01:46:41 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _rawBits(0)
{
}

Fixed::Fixed(const int integerValue)
{
	_rawBits = integerValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	_rawBits = (int)(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}

Fixed::~Fixed(void)
{
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

bool	Fixed::operator>(const Fixed &other) const
{
	return (_rawBits > other._rawBits);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (_rawBits < other._rawBits);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (_rawBits >= other._rawBits);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (_rawBits <= other._rawBits);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (_rawBits != other._rawBits);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(_rawBits + other._rawBits);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(_rawBits - other._rawBits);
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;
	long	raw;

	raw = (long)(_rawBits) * (long)(other._rawBits);
	result.setRawBits((int)(raw >> _fractionalBits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;
	long	raw;

	raw = ((long)(_rawBits) << _fractionalBits) / other._rawBits;
	result.setRawBits((int)(raw));
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	++_rawBits;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++_rawBits;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	--_rawBits;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--_rawBits;
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
