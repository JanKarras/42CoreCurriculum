/* --- PhoneBook.h --- */

/* ------------------------------------------
Author: undefined
Date: 10/24/2024
------------------------------------------ */

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
