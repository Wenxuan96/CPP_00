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
		void overwriteContact(const Contact&contactInfo, int n);
		int	numOfContacts() const;
		Contact getContact(int n) const;
};

#endif