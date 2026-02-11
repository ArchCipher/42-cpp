#include "Contact.hpp"

void Contact::setFirstName(string name)
{
    firstName = name;
}

void Contact::setLastName(string name)
{
    lastName = name;
}

void Contact::setNickName(string name)
{
    nickName = name;
}

void Contact::setNumber(string num)
{
    phoneNumber = num;
}

void Contact::setDarkSecret(string secret)
{
    darkSecret = secret;
}

const string  &Contact::getFirstName() const
{
    return (firstName);
}

const string  &Contact::getLastName() const
{
    return (lastName);
}

const string  &Contact::getNickName() const
{
    return (nickName);
}
