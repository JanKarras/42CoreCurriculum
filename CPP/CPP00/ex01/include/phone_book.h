/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:17:07 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/30 13:19:59 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "../classes/headers/Contact.h"
#include "../classes/headers/PhoneBook.h"

bool	addContact(PhoneBook *phonebook);
bool	search(PhoneBook *phonebook);

#endif
