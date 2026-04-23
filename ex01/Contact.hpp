#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
        std::string name;
        std::string phone;

    public:
        Contact();
        Contact(std::string inputName, std::string inputNum);

        void setName(std::string inputName);
        void setPhone(std::string inputNum);
        std::string getName() const;
        std::string getPhone() const; 
};

#endif
