/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 02:26:04 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/04 02:26:05 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cctype>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	else
	{
		for (int i = 1; i < argc; i++)
			for (int j = 0; argv[i][j]; j++)
				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
	}
	std::cout << '\n';
	return (0);
}
