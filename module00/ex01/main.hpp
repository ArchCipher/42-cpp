#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include "PhoneBook.hpp"

#define PROMPT "What do you want to do: ADD/SEARCH/EXIT"
#define E_INDEX "Error: Index out of range"
#define E_PH_NUM "Error: Enter a valid phone number"

using std::cin;
using std::cout;
using std::string;
using std::getline;

bool add_contact(PhoneBook &book);

#endif