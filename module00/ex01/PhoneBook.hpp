#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
    Contact contacts[MAX_CONTACTS];
    unsigned int idx : 3;

  public:
    void setContact(const Contact &contact);
    const Contact &getContact(unsigned int idx) const;
};

#endif