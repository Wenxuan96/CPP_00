#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	for(int i = 0; i < 8; i++)
		contacts[i] = Contact();
}

void Phonebook::addContact(const Contact&contactInfo, int n)
{
	contacts[n] = contactInfo;
}

void Phonebook::overwriteContact(const Contact&contactInfo, int n)
{
	contacts[n] = contactInfo;
}

Contact Phonebook::getContact(int n) const
{
	return contacts[n];
}

int	Phonebook::numOfContacts() const
{
	int i = 0;

	while(contacts[i].getFirstName() != "")
		i++;
	return i;
}