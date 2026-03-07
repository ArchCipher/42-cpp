#include "main.hpp"

bool search_contact(const PhoneBook &book);
void display_contact(const Contact &cont, const string &idx);
void print_field(const string &str);

/*
        NAME
                phonebook
    USAGE:
        ./phonebook
        ADD: add a new contact
        SEARCH: display a specific contact
        EXIT: exit the program
        DESCRIPTION:
                Phonebook that can store a maximum of 8 contacts. If the user
   tries to add a 9th contact, the oldest one is replaced by the new one. No
   dynamic allocation, contacts is an array of 8 Contact objects. Contact class
   represents a phonebook contact. PhoneBook class has an array of 8 Contact
   objects.

        SEARCH: display a specific contact as a list of 4 columns: index, first
        name, last name, and nickname. Each column is 10 characters wide. A
        pipe character (’|’) separates them. The text is right-aligned, and if
        the text is longer than the column, it is truncated and the last
        displayable character is replaced by a dot (’.’).
    REFERENCE:
        https://cplusplus.com/reference/iomanip/
        https://cplusplus.com/reference/string/string/
*/

/*
NOTE:
    cin stops at space and doesn't read until newline
    getline reads until newline

    do not mix getline and cin:
    if getline is used after cin, it would only read the newline at first
*/

int  main()
{
    PhoneBook book;
    string    str;

    cout << PROMPT << "\n";
    getline(cin, str);
    while (cin && str != "EXIT")
    {
        if (str == "ADD" && !add_contact(book))
            return (1);
        else if (str == "SEARCH" && !search_contact(book))
            return (1);
        cout << PROMPT << "\n";
        getline(cin, str);
    }
    return (0);
}

bool valid_index(const string &s)
{
    if (s.length() != 1)
        return (false);
    return (std::isdigit(s[0]) && (s[0] - '0') < MAX_CONTACTS);
}

bool search_contact(const PhoneBook &book)
{
    string       str;
    unsigned int idx;

    cout << "Enter index of entry: ";
    getline(cin, str);
    while (cin && !valid_index(str))
    {
        cout << E_INDEX << "\n";
        cout << "Enter index of entry: ";
        getline(cin, str);
    }
    if (!cin)
        return (false);
    idx = static_cast<unsigned int>(str[0]) - '0';
    display_contact(book.getContact(idx), str);
    return (true);
}

void display_contact(const Contact &cont, const string &idx)
{
    string str;
    int    field;

    print_field(idx);
    cout << "|";
    print_field(cont.getFirstName());
    cout << "|";
    print_field(cont.getLastName());
    cout << "|";
    print_field(cont.getNickName());
    cout << "\n";
}

void print_field(const string &str)
{
    int len;
    int pad;

    len = str.length();
    if (len > 10)
    {
        cout.write(&str[0], 9) << ".";
        return;
    }
    cout.width(10);
    cout << str;
}
