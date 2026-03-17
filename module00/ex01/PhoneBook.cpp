#include "PhoneBook.hpp"
#include <iostream>

using std::cin;
using std::cout;

PhoneBook::PhoneBook(void) : idx(0) {}

void PhoneBook::addContact()
{
    Contact contact;
    contact.setFirstName(getInput("First Name"));
    contact.setLastName(getInput("Last Name"));
    contact.setNickName(getInput("Nick Name"));
    contact.setNumber(getNumber());
    contact.setDarkSecret(getInput("Dark Secret"));
    if (cin)
        contacts[idx++] = contact;
}

void PhoneBook::searchContact() const
{
    string str = getIndex();
    if (cin)
        displayContact(str);
}

void PhoneBook::displayContact(const string &str) const
{
    printField(str);
    cout << "|";
    unsigned int idx = str[0] - '0';
    printField(contacts[idx].getFirstName());
    cout << "|";
    printField(contacts[idx].getLastName());
    cout << "|";
    printField(contacts[idx].getNickName());
    cout << "\n";
}

void PhoneBook::printField(const string &str)
{
    if (str.length() > COLUMN_WIDTH)
    {
        cout.write(str.data(), (COLUMN_WIDTH - 1)) << ".";
        return;
    }
    cout.width(COLUMN_WIDTH);
    cout << str;
}

string PhoneBook::getInput(const string &name)
{
    if (!cin)
        return ("");
    cout << name << ": ";
    string str;
    while (std::getline(cin, str) && str.empty())
    {
        cout << "ERROR: " << name << " cannot be empty\n" << name << ": ";
    }
    return (str);
}

string PhoneBook::getNumber(void)
{
    if (!cin)
        return ("");
    cout << "Phone Number: ";
    string str;
    while (std::getline(cin, str) && (str.empty() || !validNumber(str)))
    {
        if (str.empty())
            cout << "Error: Phone Number cannot be empty\n";
        else
            cout << "Error: invalid phone number\n";
        cout << "Phone Number: ";
    }
    return (str);
}

bool PhoneBook::validNumber(const string &str)
{
    size_t len = str.length();
    size_t i = 0;
    size_t digit_count = 0;

    if (len > 1 && str[i] == '+')
        i++;
    while (i < len)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return (false);
        i++;
        digit_count++;
    }
    return (digit_count >= MIN_PHONE_LEN && digit_count <= MAX_PHONE_LEN);
}

string PhoneBook::getIndex()
{
    if (!cin)
        return ("");
    cout << "Enter index of entry: ";
    string str;
    while (std::getline(cin, str) && !validIndex(str))
    {
        cout << "Error: Index out of range\n"
             << "Enter index of entry: ";
    }
    return (str);
}

bool PhoneBook::validIndex(const string &str)
{
    if (str.length() != 1)
        return (false);
    return (std::isdigit(str[0]) && (str[0] - '0') < MAX_CONTACTS);
}
