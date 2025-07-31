/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:46:18 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:49:30 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include "../../include/phone_book.h"

class Contact {
public:
	Contact();
	~Contact();

	std::string getFirstName() const;
	std::string getLastName()const;
	std::string getNickname()const;
	std::string getPhoneNumber()const;
	std::string getDarkestSecret()const;

	void setFirstName(const std::string& value);
	void setLastName(const std::string& value);
	void setNickname(const std::string& value);
	void setPhoneNumber(const std::string& value);
	void setDarkestSecret(const std::string& value);

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif // CONTACT_H
