#include "Phonebook.hpp"
#include <iostream>

std::string validateInput()
{
    std::string input;

    while (true)
    {
        if (!std::getline(std::cin, input))   // Ctrl+D
            exit(0);

        if (!input.empty())
            return input;

        std::cout << "Invalid input, enter again: ";
    }
}

bool isNumber(const std::string& s)
{
    if (s.empty() || s.length() > 15)
        return false;

    for (size_t i = 0; i < s.length(); i++)
        if (!std::isdigit(s[i]))
            return false;

    return true;
}

std::string validateNumber()
{
    std::string input;

    while (true)
    {
        if (!std::getline(std::cin, input))   // Ctrl+D
            exit(0);

        if (!input.empty() && isNumber(input))
            return input;

        std::cout << "Expecting no more than 15 numeric values, enter again: ";
    }
}

Contact createContact(void)
{
    Contact newcontact;

    std::cout << "Please enter your first name: ";
    newcontact.setFirstName(validateInput());

    std::cout << "Please enter your last name: ";
    newcontact.setLastName(validateInput());

    std::cout << "Please enter your nickname: ";
    newcontact.setNickname(validateInput());

    std::cout << "Please enter your phone number: ";
    newcontact.setPhone(validateNumber());

    std::cout << "Please enter your dark secret: ";
    newcontact.setSecret(validateInput());

    return newcontact;
}

std::string format(std::string txt)
{
    if (txt.length() > 10)
        return txt.substr(0, 9) + ".";
    return txt;
}

void displayAll(Phonebook&newPhonebook)
{
    int count = newPhonebook.numOfContacts();

    std::cout << std::right << std::setw(10) << "index" << "|"
              << std::right << std::setw(10) << "first name" << "|"
              << std::right << std::setw(10) << "last name" << "|"
              << std::right << std::setw(10) << "nickname" << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i <= count - 1; i++)
    {
        if (i == 8)
            break;
        std::cout << std::right << std::setw(10) << i + 1 << "|"
                  << std::right << std::setw(10) << format(newPhonebook.getContact(i).getFirstName()) << "|"
                  << std::right << std::setw(10) << format(newPhonebook.getContact(i).getLastName()) << "|"
                  << std::right << std::setw(10) << format(newPhonebook.getContact(i).getNickname()) << "|" << std::endl;
    }
}

void prtSearch(int index, Phonebook&newPhonebook)
{
    Contact searchResult;

    searchResult = newPhonebook.getContact(index);
    std::cout << "First name: " << searchResult.getFirstName() << std::endl;
    std::cout << "Last name: " << searchResult.getLastName() << std::endl;
    std::cout << "Nickname: " << searchResult.getNickname() << std::endl;
    std::cout << "Phone number: " << searchResult.getPhone() << std::endl;
    std::cout << "Dark secret: " << searchResult.getSecret() << std::endl;
}

int main(int argc, char **argv)
{
    std::string input;
    Phonebook newPhonebook;
    Contact newcontact;
    int numContact = -1;
    int index;

    Phonebook();
    while (true)
    {
        std::cout << "Please enter one of these commands: 'ADD', 'SEARCH', 'EXIT'." << std::endl;
        if (!std::getline(std::cin, input))
            exit(0);
        if (input == "EXIT")
            return 0;
        else if (input == "ADD")
        {
            newcontact = createContact();
            numContact++;
            newPhonebook.addContact(newcontact, numContact % 8);
        }
        else if (input == "SEARCH")
        {
            displayAll(newPhonebook);

            std::string strIndex;
            int index;

            while (true)
            {
                std::cout << "Please type an index number to display the contact person: ";
                if (!std::getline(std::cin, strIndex))
                    exit(0);
                if (!isNumber(strIndex))
                {
                    std::cout << "Index must be a number!" << std::endl;
                    continue;
                }
                index = std::stoi(strIndex);
                std::cout << "Number of contacts: " << newPhonebook.numOfContacts() << std::endl;
                if (index < 1 || index > newPhonebook.numOfContacts() || index == 9)
                {
                    std::cout << "Index out of range!" << std::endl;
                    continue;
                }
                break;
            }
            prtSearch(index - 1, newPhonebook);
        }
    }

    return 0;
}