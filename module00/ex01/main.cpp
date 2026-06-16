#include "PhoneBook.hpp"
#include <iostream>

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
        tries to add a 9th contact, the oldest one is replaced by the
        new one. No dynamic allocation, contacts is an array of 8 Contact
        objects. Contact class represents a phonebook contact. PhoneBook class
        has an array of 8 Contact objects.

        SEARCH: display a specific contact as a list of 4 columns: index, first
        name, last name, and nickname. Each column is 10 characters wide. A
        pipe character ('|') separates them. The text is right-aligned, and if
        the text is longer than the column, it is truncated and the last
        displayable character is replaced by a dot ('.').
*/

/*
NOTE:
    cin stops at space and doesn't read until newline
    getline reads until newline

    do not mix getline and cin:
    if getline is used after cin, it would only read the newline at first
*/

int main()
{
    PhoneBook         book;
    string            str;

    const std::string prompt = "What do you want to do: ADD/SEARCH/EXIT\n";
    std::cout << prompt;
    while (std::getline(std::cin, str) && str != "EXIT")
    {
        if (str == "ADD")
            book.addContact();
        else if (str == "SEARCH")
            book.searchContact();
        if (std::cin)
            std::cout << prompt;
    }
    return (0);
}
