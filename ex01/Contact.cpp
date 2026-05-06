#include "Contact.hpp"

Contact::Contact():
    first_name(""), last_name(""), nickname(""),
    phone(""), dark_secret("") {}

void Contact::setFirstName(std::string inputName)
{
    first_name = inputName;
}

void Contact::setLastName(std::string inputName)
{
    last_name = inputName;
}

void Contact::setNickname(std::string inputName)
{
    nickname = inputName;
}

void Contact::setPhone(std::string inputNum)
{
    phone = inputNum;
}

void Contact::setSecret(std::string inputSecret)
{
    dark_secret = inputSecret;
}

std::string Contact::getFirstName() const
{
    return first_name;
}

std::string Contact::getLastName() const
{
    return last_name;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhone() const
{
    return phone;
}

std::string Contact::getSecret() const
{
    return dark_secret;
}