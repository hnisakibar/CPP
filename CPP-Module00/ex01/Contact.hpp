/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 02:25:51 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/04 02:25:52 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
public:
	Contact(void);

	void				setData(const std::string &firstName,
							const std::string &lastName,
							const std::string &nickName,
							const std::string &phoneNumber,
							const std::string &darkestSecret);

	bool				isEmpty(void) const;

	const std::string	&getFirstName(void) const;
	const std::string	&getLastName(void) const;
	const std::string	&getNickName(void) const;
	const std::string	&getPhoneNumber(void) const;
	const std::string	&getDarkestSecret(void) const;

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	bool		_empty;
};

#endif
