/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:54:33 by akutludo          #+#    #+#             */
/*   Updated: 2025/11/04 16:54:34 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACT 8

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class PhoneBook
{
	private:
		Contact	contacts[MAX_CONTACT];
		size_t	iter;
		bool	isContactFull;

	public:
		PhoneBook();

		void	listContacts(void) const;
		void	searchContact(const size_t index) const;
		void	addNewContact(const Contact& newContact);
		size_t	getCount(void) const;
};

#endif
