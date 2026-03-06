#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

using std::string;

class Contact {
    string firstName;
    string lastName;
    string nickName;
    string phoneNumber;
    string darkSecret;

  public:
    void setFirstName(string name);
    void setLastName(string name);
    void setNickName(string name);
    void setNumber(string num);
    void setDarkSecret(string secret);
    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getNickName() const;
};

#endif