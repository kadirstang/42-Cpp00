/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:50:40 by akutludo          #+#    #+#             */
/*   Updated: 2025/11/04 16:50:42 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, const char * const argv[])
{
	std::string argument;

	if (1 == argc)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	else
	{
		for (int i = 1; argc > i; i++)
		{
			argument = argv[i];
			for (size_t j = 0; j < argument.length(); j++)
				argument[j] = std::toupper(argument[j]);
			std::cout << argument;
		}
		std::cout << std::endl;
	}
	return 0;
}
