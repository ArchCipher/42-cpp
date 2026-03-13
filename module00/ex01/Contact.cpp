#include "Contact.hpp"

void Contact::setFirstName(const string &name)
{
    firstName = name;
}

void Contact::setLastName(const string &name)
{
    lastName = name;
}

void Contact::setNickName(const string &name)
{
    nickName = name;
}

void Contact::setNumber(const string &num)
{
    phoneNumber = num;
}

void Contact::setDarkSecret(const string &secret)
{
    darkSecret = secret;
}

const string &Contact::getFirstName() const
{
    return (firstName);
}

const string &Contact::getLastName() const
{
    return (lastName);
}

const string &Contact::getNickName() const
{
    return (nickName);
}

const string &Contact::getNumber() const
{
    return (phoneNumber);
}

const string &Contact::getDarkSecret() const
{
    return (darkSecret);
}
