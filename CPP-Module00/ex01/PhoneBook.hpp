/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 02:25:36 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/04 02:25:37 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
public: 
	PhoneBook(void);

	~PhoneBook(void);
	
	bool	addContact(void);

	void	searchContact(void) const;

private:
	Contact	_contacts[8];
	int		_count;
	int		_nextSlot;

	static bool			readNonEmptyField(const std::string &label,
						std::string &value);

	static std::string	formatColumn(const std::string &value);

	bool				isValidIndex(const std::string &input, int &index) const;

	void				printContactRow(int index) const;

	void				printContactDetails(int index) const;
};

#endif
