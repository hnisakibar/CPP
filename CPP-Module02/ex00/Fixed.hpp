/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:14:38 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/15 18:15:38 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &other);
	Fixed	&operator=(const Fixed &other);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};

#endif
