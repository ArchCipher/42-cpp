#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

using std::string;

class Contact
{
    string firstName;
    string lastName;
    string nickName;
    string phoneNumber;
    string darkSecret;

  public:
    void          setFirstName(const string &name);
    void          setLastName(const string &name);
    void          setNickName(const string &name);
    void          setNumber(const string &num);
    void          setDarkSecret(const string &secret);
    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getNickName() const;
    const string &getNumber() const;
    const string &getDarkSecret() const;
};

#endif