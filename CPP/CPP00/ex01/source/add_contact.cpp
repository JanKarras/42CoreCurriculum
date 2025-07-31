/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:16:24 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/30 13:36:17 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phone_book.h"

bool	get_input(std::string str, Contact *contact, int *i) {
	std::cout << str << std::endl;
	if (!getline(std::cin, str)) {
		if (std::cin.eof())
			std::cout << "EOF reached exiting\n";
		else
			std::cout << "Input error\n";
		*i = 10;
		return (true);
	}
	if (str.empty()) {
		return (std::cout << "Empty input\n", true);
	} else if (*i == 3) {
		for (int j = 0; str[j]; j++)
			if (!isdigit(str[j]))
				return (std::cout << "Phonenumber only allows digits\n", true);
	}
	if (*i == 0)
		contact->setFirstName(str);
	else if (*i == 1)
		contact->setLastName(str);
	else if (*i == 2)
		contact->setNickname(str);
	else if (*i == 3)
		contact->setPhoneNumber(str);
	else if (*i == 4)
		contact->setDarkestSecret(str);
	return (false);
}

bool	addContact(PhoneBook	*phonebook) {
	Contact		contact;
	int			i;

	i = 0;
	while (i < 5)
	{
		if (i == 0) {
			if (get_input("Please enter first name", &contact, &i))
				continue;
		} else if (i == 1) {
			if (get_input("Please enter last name", &contact, &i))
				continue;
		} else if (i == 2) {
			if (get_input("Please enter nick name", &contact, &i))
				continue;
		} else if (i == 3) {
			if (get_input("Please enter phonenumber", &contact, &i))
				continue;
		} else if (i == 4) {
			if (get_input("Please enter darkest secret", &contact, &i))
				continue;
		}
		i++;
	}
	if (i == 10)
		return (true);
	phonebook->addContact(contact);
	return (false);
}
