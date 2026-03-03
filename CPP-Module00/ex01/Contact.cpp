/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 02:25:58 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/04 02:25:59 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

Contact::Contact(void) : _empty(true)
{
}

void	Contact::setData(const std::string &firstName,
			const std::string &lastName,
			const std::string &nickName,
			const std::string &phoneNumber,
			const std::string &darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickName = nickName;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
	_empty = false;
}

bool	Contact::isEmpty(void) const
{
	return (_empty);
}

const std::string	&Contact::getFirstName(void) const
{
	return (_firstName);
}

const std::string	&Contact::getLastName(void) const
{
	return (_lastName);
}

const std::string	&Contact::getNickName(void) const
{
	return (_nickName);
}

const std::string	&Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

const std::string	&Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}
