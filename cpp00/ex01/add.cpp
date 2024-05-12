#include "PhoneBook.hpp"

static int add_a_field(Contact *contact, size_t field)
{
	std::string error;
	std::string entry;

	while (is_empty(entry))
	{
		std::cout << error;
		if (field == first_name)
			std::cout << "First name: ";
		if (field == last_name)
			std::cout << "Last name: ";
		if (field == nick_name)
			std::cout << "Nick name: ";
		if (field == number)
			std::cout << "Phone Number: ";
		if (field == secret)
			std::cout << "Darkest secret: ";
		std::getline(std::cin, entry);
		if (std::cin.eof())
			return (-1);
		if (!error.empty())
			std::cout << UP;
		std::cout << UP ERASE;
		if (is_empty(entry))
			error = RED "ERROR: " RESET RRED "can't be empty.\n" RESET;
		else
			error = "";
	}
	contact->set(field, remove_whitespaces(entry));
	return (0);
}

static void add_to_phonebook(PhoneBook *pb, Contact new_contact)
{
	if (pb->get_index() < 8)
		pb->set_contact(new_contact, pb->increment_index());
	else
	{
		for (int i = 0; i < 7; i++)
			pb->set_contact(pb->get_contact(i + 1), i);
		pb->set_contact(new_contact, 7);
	}
}

int add(PhoneBook *pb)
{
	Contact new_contact;

	std::cout << CLEAR;
	std::cout << MAGENTA "      🦑 New Contact 🦑" RESET << std::endl
			  << std::endl;
	if (add_a_field(&new_contact, first_name) == -1)
		return (-1);
	if (add_a_field(&new_contact, last_name) == -1)
		return (-1);
	if (add_a_field(&new_contact, nick_name) == -1)
		return (-1);
	if (add_a_field(&new_contact, number) == -1)
		return (-1);
	if (add_a_field(&new_contact, secret) == -1)
		return (-1);
	add_to_phonebook(pb, new_contact);
	return (0);
}
