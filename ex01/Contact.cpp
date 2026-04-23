#include "Contact.hpp"

Contact::Contact():
    name(""), phone(""){}

Contact::Contact(std::string inputName, std::string inputNum):
    name(inputName), phone(inputNum) {}

void Contact::setName(std::string inputName)
{
    name = inputName;
}

void Contact::setPhone(std::string inputNum)
{
    phone = inputNum;
}

std::string Contact::getName() const
{
    return name;
}

std::string Contact::getPhone() const
{
    return phone;
}