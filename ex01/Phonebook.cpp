#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	for(int i = 0; i < 8; i++)
		contacts[i] = Contact();
}

void Phonebook::addContact(const Contact&name, int n)
{
	contacts[n] = name;
}

void Phonebook::overwriteContact(const Contact&name)
{
	contacts[0] = name;
}

int	Phonebook::numOfContacts() const
{
	int count = 0;

	for(int i = 0; i < 8; i++)
	{
		if (contacts[i].getName() != "")
			count++;
	}
	return count;
}