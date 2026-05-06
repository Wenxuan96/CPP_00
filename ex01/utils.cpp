#include "Phonebook.hpp"
#include <iostream>

std::string format(std::string txt)
{
    if (txt.length() > 10)
        return txt.substr(0, 9) + ".";
    return txt;
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