#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone;
        std::string dark_secret;

    public:
        Contact();

        void setFirstName(std::string inputName);
        void setLastName(std::string inputName);
        void setNickname(std::string inputName);
        void setPhone(std::string inputNum);
        void setSecret(std::string inputSecret);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhone() const;
        std::string getSecret() const;
};

#endif
