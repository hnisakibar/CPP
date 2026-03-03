/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 02:24:53 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/04 02:24:54 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include <climits>
#include <cctype>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(void) : _count(0), _nextSlot(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

bool	PhoneBook::readNonEmptyField(const std::string &label, std::string &value)
{
	while (true)
	{
		std::cout << label;
		if (!std::getline(std::cin, value))
			return (false);
		if (!value.empty())
			return (true);
		std::cout << "This field cannot be empty." << '\n';
	}
}

std::string	PhoneBook::formatColumn(const std::string &value)
{
	if (value.length() <= 10)
		return (value);
	return (value.substr(0, 9) + ".");
}

bool	PhoneBook::isValidIndex(const std::string &input, int &index) const
{
	long	value;
	int		digit;

	if (input.empty())
		return (false);
	value = 0;
	for (std::string::size_type i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return (false);
		digit = input[i] - '0';
		if (value > (LONG_MAX - digit) / 10)
			return (false);
		value = (value * 10) + digit;
		if (value > INT_MAX)
			return (false);
	}
	index = static_cast<int>(value);
	return (true);
}

void	PhoneBook::printContactRow(int index) const
{
	const Contact	&contact = _contacts[index];

	std::cout << std::setw(10) << index << '|'
		<< std::setw(10) << formatColumn(contact.getFirstName()) << '|'
		<< std::setw(10) << formatColumn(contact.getLastName()) << '|'
		<< std::setw(10) << formatColumn(contact.getNickName()) << '\n';
}

void	PhoneBook::printContactDetails(int index) const
{
	const Contact	&contact = _contacts[index];

	std::cout << "First name: " << contact.getFirstName() << '\n';
	std::cout << "Last name: " << contact.getLastName() << '\n';
	std::cout << "Nickname: " << contact.getNickName() << '\n';
	std::cout << "Phone number: " << contact.getPhoneNumber() << '\n';
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << '\n';
}

bool	PhoneBook::addContact(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (!readNonEmptyField("First name: ", firstName))
		return (false);
	if (!readNonEmptyField("Last name: ", lastName))
		return (false);
	if (!readNonEmptyField("Nickname: ", nickName))
		return (false);
	if (!readNonEmptyField("Phone number: ", phoneNumber))
		return (false);
	if (!readNonEmptyField("Darkest secret: ", darkestSecret))
		return (false);

	_contacts[_nextSlot].setData(firstName, lastName, nickName, phoneNumber,
		darkestSecret);
	_nextSlot = (_nextSlot + 1) % 8;
	if (_count < 8)
		_count++;
	std::cout << "Contact saved." << '\n';
	return (true);
}

void	PhoneBook::searchContact(void) const
{
	std::string	input;
	int			index;

	if (_count == 0)
	{
		std::cout << "PhoneBook is empty." << '\n';
		return ;
	}
	std::cout << std::setw(10) << "Index" << '|'
		<< std::setw(10) << "First name" << '|'
		<< std::setw(10) << "Last name" << '|'
		<< std::setw(10) << "Nickname" << '\n';
	for (int i = 0; i < _count; i++)
		printContactRow(i);
	std::cout << "Index to display: ";
	if (!std::getline(std::cin, input))
		return ;
	if (!isValidIndex(input, index) || index < 0 || index >= _count)
	{
		std::cout << "Invalid index." << '\n';
		return ;
	}
	printContactDetails(index);
}
