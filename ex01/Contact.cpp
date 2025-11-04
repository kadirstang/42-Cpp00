/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:52:02 by akutludo          #+#    #+#             */
/*   Updated: 2025/11/04 16:52:04 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

void	Contact::setFirstName(const std::string& _firstName)
{
	this->firstName = _firstName;
}

void	Contact::setLastName(const std::string& _lastName)
{
	this->lastName = _lastName;
}

void	Contact::setNickname(const std::string& _nickname)
{
	this->nickname = _nickname;
}

void	Contact::setPhoneNumber(const std::string& _phoneNumber)
{
	this->phoneNumber = _phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& _darkestSecret)
{
	this->darkestSecret = _darkestSecret;
}

std::string	Contact::getFirstName() const
{
	return this->firstName;
}

std::string	Contact::getLastName() const
{
	return this->lastName;
}

std::string	Contact::getNickname() const
{
	return this->nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return this->darkestSecret;
}
