/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:46:14 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:49:19 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "../../include/phone_book.h"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();

	void addContact(const Contact& contact);
	Contact getContact(int index) const;
	int getContactCount() const;

private:
	Contact contacts[8];
	int contact_count;
};

#endif // PHONEBOOK_H
