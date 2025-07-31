/* --- Contact.h --- */

/* ------------------------------------------
Author: undefined
Date: 10/24/2024
------------------------------------------ */

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
