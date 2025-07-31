/* --- PhoneBook.cpp --- */

/* ------------------------------------------
author: undefined
date: 10/24/2024
------------------------------------------ */

#include "../../include/phone_book.h"

PhoneBook::PhoneBook() {
    contact_count = -1;
}

PhoneBook::~PhoneBook() {

}

void PhoneBook::addContact(const Contact& contact) {
	contact_count++;
	contacts[contact_count % 8] = contact;
}

Contact PhoneBook::getContact(int index) const {
	if (index >= 0 && index < 8) {
		return contacts[index];
	}
	return Contact();
}

int PhoneBook::getContactCount() const {
	return contact_count;
}
