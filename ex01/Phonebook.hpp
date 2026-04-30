#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
	public:
		Phonebook();
		void addContact(const Contact&contactInfo, int n);
		void overwriteContact(const Contact&name);
		int	numOfContacts() const;
};

#endif