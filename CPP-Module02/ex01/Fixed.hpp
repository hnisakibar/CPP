/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:02:48 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/16 01:14:38 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const int integerValue);
	Fixed(const float floatValue);
	Fixed(const Fixed &other);
	Fixed	&operator=(const Fixed &other);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif
