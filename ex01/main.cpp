#include "Phonebook.hpp"
#include <iostream>

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

int main()
{
    std::string input;
    Phonebook newPhonebook;
    Contact newcontact;
    int numContact = -1;

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
            if (newPhonebook.numOfContacts() == 0)
            {
                std::cout << "Phonebook empty! Search only after adding at least on contact." << std::endl;
                continue;
            }
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
                try
                {
                    index = std::stoi(strIndex);
                }
                catch (const std::exception& e)
                {
                    index = -1;
                }
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