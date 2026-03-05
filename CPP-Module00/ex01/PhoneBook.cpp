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

static std::string trim(const std::string &s)
{
    std::string::size_type start = 0;
    while (start < s.size() && std::isspace(s[start]))
        ++start;

    std::string::size_type end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        --end;

    return s.substr(start, end - start);
}

bool	PhoneBook::readNonEmptyField(const std::string &label, std::string &value)
{
	while (true)
	{
		std::cout << label;
		if (!std::getline(std::cin, value))
			return (false);
		value = trim(value);
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
    if (input.length() != 1 || input[0] < '0' || input[0] > '7')
        return false;

    index = input[0] - '0';
    return (index < _count);
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
	while (true)
	{
    	std::cout << "Index to display: ";
    	if (!std::getline(std::cin, input))
    	    return;

    	if (isValidIndex(input, index))
    	    break;

    	std::cout << "Invalid index." << '\n';
	}
	printContactDetails(index);
}
