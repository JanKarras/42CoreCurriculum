/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:03:48 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/30 15:07:06 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phone_book.h"

int	main(void) {
	PhoneBook	phonebook;
	bool		run;
	std::string	cmd;

	run = true;
	while (run)
	{
		std::cout << "cmd list: ADD, SEARCH, EXIT\n";
		std::cout << "Please enter cmd :";
		if (!getline(std::cin, cmd)) {
			if (std::cin.eof())
				std::cout << "\nEOF reached exiting\n";
			else
				std::cout << "\nInput error\n";
			return (0);
		}
		if (cmd == "ADD") {
			if (addContact(&phonebook))
				return (1);
		}
		else if (cmd == "SEARCH") {
			if (search(&phonebook))
				return (1);
		}
		else if (cmd == "EXIT")
			run = false;
		else
			std::cout << cmd << " is an unknown cmd\n";
	}
	return (0);
}
