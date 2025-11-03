#include "PhoneBook.hpp"
#include <iostream>
#include <string>

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void	actions_error(std::string error)
{
	std::cerr << RED << "❌ Error: " << error << RESET << std::endl;
}

void	actions_add(PhoneBook& book)
{
	Contact		contact;
	std::string	info[5];

	std::cout << std::endl;
	std::cout << CYAN << BOLD << "📝 Adding New Contact" << RESET << std::endl;
	std::cout << "────────────────────────────────" << std::endl << std::endl;

	std::cout << YELLOW << "Contact's First Name: " << RESET;
	std::getline(std::cin, info[0]);
	std::cout << YELLOW << "Contact's Last Name: " << RESET;
	std::getline(std::cin, info[1]);
	std::cout << YELLOW << "Contact's Nickname: " << RESET;
	std::getline(std::cin, info[2]);
	std::cout << YELLOW << "Contact's Phone Number: " << RESET;
	std::getline(std::cin, info[3]);
	std::cout << YELLOW << "Contact's Darkest Secret: " << RESET;
	std::getline(std::cin, info[4]);

	for(size_t i = 0; i < 5; i++)
	{
		if (info[i].empty())
			return (actions_error("Empty field error. Contact not added."));
	}
	contact.setFirstName(info[0]);
	contact.setLastName(info[1]);
	contact.setNickname(info[2]);
	contact.setPhoneNumber(info[3]);
	contact.setDarkestSecret(info[4]);
	book.addNewContact(contact);

	std::cout << std::endl;
	std::cout << GREEN << "✓ Contact added successfully!" << RESET << std::endl;
}

void	actions_search(PhoneBook& book)
{
	std::string	str;
	size_t		index;

	std::cout << std::endl;
	book.listContacts();
	std::cout << std::endl;
	std::cout << YELLOW << "Enter index of contact you want to search: " << RESET;
	std::getline(std::cin, str);
	if ((str.length() > 1 || str.length() < 1) && (str[0] < '1' || str[0] > MAX_CONTACT + '0'))
		return (actions_error("Wrong index error."));
	index = str[0] - '0';
	std::cout << std::endl;
	book.searchContact(index);
}

void	actions_close(bool& closed)
{
	closed = true;
	std::cout << std::endl;
	std::cout << MAGENTA << "👋 You closed the PhoneBook. Goodbye!" << RESET << std::endl;
	std::cout << std::endl;
}

void	actions_again(void)
{
	std::cout << std::endl;
	actions_error("Command not found! Try Again!");
	std::cout << std::endl;

	std::cout << CYAN << "Available commands:" << RESET << std::endl;
	std::cout << GREEN << "  • ADD" << RESET << "    - Add a new contact" << std::endl;
	std::cout << GREEN << "  • SEARCH" << RESET << " - Search for a contact by index" << std::endl;
	std::cout << GREEN << "  • EXIT" << RESET << "   - Exit the program" << std::endl;
}
