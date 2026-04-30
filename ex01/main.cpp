#include "Phonebook.hpp"



int main(int argc, char **argv) 
{
    std::string input;

    Phonebook();
    while (true)
    {
        std::cout << "Please enter your command (Choose one of these three: 'ADD', 'SEARCH', 'EXIT'):" << std::endl;
        std::getline(std::cin, input);

        if (input == "EXIT")
            return 0;
        else if (input == "ADD")
        else if (input == "SEARCH")
    }

    return 0;
}