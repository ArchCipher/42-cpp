# include "main.hpp"

bool set_field(Contact &cont, void (Contact::*setter)(string), const string &name, string (*input_func)(const string&));
string get_input(const string &name);
string get_number(const string &name);
bool valid_number(const string &str);

bool add_contact(PhoneBook &book)
{
    Contact cont;
    string  str;

    if (!set_field(cont, &Contact::setFirstName, "First Name", get_input))
        return (false);
    if (!set_field(cont, &Contact::setLastName, "Last Name", get_input))
        return (false);
    if (!set_field(cont, &Contact::setNickName, "Nick Name", get_input)) 
        return (false);
    if (!set_field(cont, &Contact::setNumber, "Phone Number", get_number)) 
        return (false);
    if (!set_field(cont, &Contact::setDarkSecret, "Dark Secret", get_input))    
        return (false);
    book.setContact(cont);
    return (true);
}

/*
NOTE:
    Contact *cont: Pointer(passed by reference)
    Contact &cont: Passed by reference, but
    - cannot be null
    - doesn't need to be dereferenced
    - cannot be reseated

    (cont.*setter)(str)
    cannot be cont.*setter(str) due to precedence
    cont.*setter(str) becomes cont.*(setter(str))
*/

bool set_field(Contact &cont, void (Contact::*setter)(string), const string &name, string (*input_func)(const string&))
{
    string str;

    str = input_func(name);
    if (!cin)
        return (false);
    (cont.*setter)(str);
    return (true);
}

string get_input(const string &name)
{
    string str;

    cout << name << ": ";
    getline(cin, str);
    while (cin && str.empty())
    {
        cout << "ERROR: " << name << " cannot be empty" << endl;
        cout << name << ": ";
        getline(cin, str);
    }
    return (str);
}

string get_number(const string &name)
{
    string  str;

    cout << name << ": ";
    getline(cin, str);
    while (cin && (str.empty() || !valid_number(str)))
    {
        if (str.empty())
            cout << "Error: " << name << " cannot be empty\n";
        else
            cout << "Error: invalid phone number\n";
        cout << name << ": ";
        getline(cin, str);
    }
    return (str);
}

bool valid_number(const string &str)
{
    size_t     digit_count;
    size_t     len;
    size_t     i;
    
    len = str.length();
    digit_count = 0;
    i = 0;
    if (len > 1 && str[i] == '+')
        i++;
    while (i < len)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return (false);
        i++;
        digit_count++;
    }
    return (digit_count >= 8 && digit_count <= 15);
}
