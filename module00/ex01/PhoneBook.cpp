#include "PhoneBook.hpp"

void PhoneBook::setContact(const Contact &contact) {
    contacts[idx++] = contact;
}

const Contact &PhoneBook::getContact(unsigned int idx) const {
    return (contacts[idx]);
}
