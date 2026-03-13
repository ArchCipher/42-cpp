#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8
#define COLUMN_WIDTH 10
#define MIN_PHONE_LEN 8
#define MAX_PHONE_LEN 15

class PhoneBook
{
    Contact       contacts[MAX_CONTACTS];
    unsigned int  idx : 3;

    void          displayContact(const string &str) const;
    static void   printField(const string &str);
    static string getInput(const string &name);
    static string getNumber(void);
    static bool   validNumber(const string &str);
    static string getIndex();
    static bool   validIndex(const string &str);

  public:
    void addContact();
    void searchContact() const;
};

#endif