#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
}
PhoneBook::~PhoneBook()
{
}

Contact PhoneBook::get_contact(int i)
{
	return (this->_contacts[i]);
}

void PhoneBook::set_contact(Contact contact, int i)
{
	this->_contacts[i] = contact;
}

int PhoneBook::get_index()
{
	return (this->_index);
}

int PhoneBook::increment_index()
{
	return (this->_index++);
}