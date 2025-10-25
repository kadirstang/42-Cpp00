#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACT 8

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
