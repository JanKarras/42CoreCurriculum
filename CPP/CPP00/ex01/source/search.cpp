/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:39:08 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/30 14:42:47 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phone_book.h"

void	print_string_len10_right(std::string string) {
	if (string.length() < 10)
		string.insert(0, 10 - string.length(), ' ');
	else if (string.length() > 10)
		string = string.substr(0, 9) + ".";
	std::cout << string;
}

void	print_contact(Contact contact, int i) {
	std::cout << "|";
	std::cout << "         " << i;
	std::cout << "|";
	print_string_len10_right(contact.getFirstName());
	std::cout << "|";
	print_string_len10_right(contact.getLastName());
	std::cout << "|";
	print_string_len10_right(contact.getNickname());
	std::cout << "|";
	std::cout << "\n";
}

void	print_full_contact(Contact contact) {
	std::cout << "first name  : " << contact.getFirstName() << std::endl;
	std::cout << "last name   : " << contact.getLastName() << std::endl;
	std::cout << "nickname    : " << contact.getNickname() << std::endl;
	std::cout << "phonenumber : " << contact.getPhoneNumber() << std::endl;
	std::cout << "dark secret : " << contact.getDarkestSecret() << std::endl;
}

void	print_header() {
	std::cout << "+-------------------------------------------+\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
	std::cout << "+-------------------------------------------+\n";
}

bool	check_input(std::string input, PhoneBook *phonebook) {
	int	num;

	if (phonebook->getContactCount() == -1)
		return (std::cout << "No contacts saved\n", true);
	if (input.empty())
		return (std::cout << "Empty input\n", true);
	for (int j = 0; input[j]; j++)
			if (!isdigit(input[j]))
				return (std::cout << "input is non digit\n", true);
	if (input.length() > 2)
		return (std::cout << "number is to big! max 7\n", true);
	num = input[0] - 48;
	if (num < 0)
		return (std::cout << "number is neagtiv\n", true);
	if (num > phonebook->getContactCount())
		return (std::cout << "number is to big! max " << phonebook->getContactCount() << std::endl, true);
	print_full_contact(phonebook->getContact(num));
	return (false);
}

bool	search(PhoneBook *phonebook) {
	std::string	input;

	print_header();
	for (int i = 0; i <= phonebook->getContactCount() && i < 8; i++)
		print_contact(phonebook->getContact(i), i);
	std::cout << "+-------------------------------------------+\n";
	while (1)
	{
		std::cout << "Pleaser enter index for details or return to leave the search menu\n";
		if (!getline(std::cin, input)) {
			if (std::cin.eof())
				std::cout << "\nEOF reached exiting\n";
			else
				std::cout << "\nInput error\n";
			return (true);
		}
		if (input == "return")
			return (false);
		if (check_input(input, phonebook))
			continue;
		else
			break;
	}
	return (false);
}
