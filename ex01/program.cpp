/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:54:43 by akutludo          #+#    #+#             */
/*   Updated: 2025/11/04 19:21:16 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void	actions_add(PhoneBook& book);
void	actions_search(PhoneBook& book);
void	actions_close(bool& closed);
void	actions_again(void);

void	the_program(PhoneBook& book, bool& closed)
{
	std::string	choice;

	std::cout << std::endl;
	std::cout << BLUE << "➜ " << RESET << "Please enter a command: ";
	if (!std::getline(std::cin, choice))
		return ;
	if (choice == "EXIT")
		actions_close(closed);
	else if (choice == "ADD")
		actions_add(book);
	else if (choice == "SEARCH")
		actions_search(book);
	else
		actions_again();

	if (!closed)
		the_program(book, closed);
}

void	welcome_book(void)
{
	std::cout << std::endl;
	std::cout << CYAN << BOLD << "═══════════════════════════════════════" << RESET << std::endl;
	std::cout << CYAN << BOLD << "    📖  PHONEBOOK MANAGER  📞" << RESET << std::endl;
	std::cout << CYAN << BOLD << "═══════════════════════════════════════" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << "Welcome to the PhoneBook program!" << std::endl;
	std::cout << "You can manage your contacts easily." << std::endl;
	std::cout << std::endl;
	std::cout << CYAN << "Available commands:" << RESET << std::endl;
	std::cout << GREEN << "  • ADD" << RESET << "    - Add a new contact" << std::endl;
	std::cout << GREEN << "  • SEARCH" << RESET << " - Search for a contact by index" << std::endl;
	std::cout << GREEN << "  • EXIT" << RESET << "   - Exit the program" << std::endl;
}

void	phone_book(void)
{
	PhoneBook	book;
	bool		closed;

	closed = false;
	welcome_book();
	the_program(book, closed);
}

int	argument_check(int argc, const char * const argv[])
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Argument error." << std::endl;
		return 1;
	}
	return 0;
}

int	main(int argc, const char * const argv[])
{
	if (argument_check(argc, argv))
		return 1;
	phone_book();
}
