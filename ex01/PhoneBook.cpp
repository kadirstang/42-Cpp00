#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

// ANSI Color Codes
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"

PhoneBook::PhoneBook()
{
	this->iter = 0;
	this->isContactFull = false;
}

static std::string formatField(const std::string& field)
{
	if (field.length() > 10) {
		return field.substr(0, 9) + ".";
	}
	return field;
}

void PhoneBook::listContacts(void) const
{
	size_t count = getCount();

	if (count == 0)
	{
		std::cout << YELLOW << "📭 PhoneBook is empty. Use ADD command to add contacts." << RESET << std::endl;
		return ;
	}

	std::cout << CYAN << BOLD << "═══════════════════════════════════════════════" << RESET << std::endl;
	std::cout << CYAN << BOLD << "              CONTACT LIST" << RESET << std::endl;
	std::cout << CYAN << BOLD << "═══════════════════════════════════════════════" << RESET << std::endl;

	std::cout << BLUE << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << RESET << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;

	for (size_t i = 0; i < count; ++i)
	{
		std::cout << std::setw(10) << std::right << (i + 1) << "|";
		std::cout << std::setw(10) << std::right << formatField(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << formatField(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << formatField(this->contacts[i].getNickname()) << std::endl;
	}
	std::cout << "═══════════════════════════════════════════════" << std::endl;
}

void	PhoneBook::searchContact(const size_t index) const
{
	size_t	count;

	count = getCount();
	if (index > MAX_CONTACT || count < index)
		std::cerr << RED << "❌ Error: Wrong index error." << RESET << std::endl;
	else
	{
		std::cout << CYAN << BOLD << "────────────────────────────────" << RESET << std::endl;
		std::cout << CYAN << BOLD << "      CONTACT DETAILS" << RESET << std::endl;
		std::cout << CYAN << BOLD << "────────────────────────────────" << RESET << std::endl;
		std::cout << YELLOW << "First Name:      " << RESET << this->contacts[index - 1].getFirstName() << std::endl;
		std::cout << YELLOW << "Last Name:       " << RESET << this->contacts[index - 1].getLastName() << std::endl;
		std::cout << YELLOW << "Nickname:        " << RESET << this->contacts[index - 1].getNickname() << std::endl;
		std::cout << YELLOW << "Phone Number:    " << RESET << this->contacts[index - 1].getPhoneNumber() << std::endl;
		std::cout << YELLOW << "Darkest Secret:  " << RESET << this->contacts[index - 1].getDarkestSecret() << std::endl;
		std::cout << "────────────────────────────────" << std::endl;
	}
}

void	PhoneBook::addNewContact(const Contact& newContact)
{
	if (MAX_CONTACT - 1 == iter)
	{
		this->contacts[MAX_CONTACT - 1] = newContact;
		this->iter = 0;
		this->isContactFull = true;
	}
	else
	{
		this->contacts[iter] = newContact;
		iter++;
	}
}
size_t	PhoneBook::getCount(void) const
{
	if (this->isContactFull)
		return (MAX_CONTACT);
	else
		return(this->iter);
}
