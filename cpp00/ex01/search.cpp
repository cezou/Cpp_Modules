#include "PhoneBook.hpp"

static int press_enter(void)
{
	std::string trash;
	std::cout << std::endl
			  << " Press enter to continue. ";
	std::getline(std::cin, trash);
	std::cout << std::endl;
	if (std::cin.eof())
		return (-1);
	return (0);
}

static void print_contact(PhoneBook pb, size_t i)
{
	std::cout << CLEAR;
	std::cout << MAGENTA "   🦑 Contact Sheet 🦑" RESET << std::endl
			  << std::endl;
	std::cout << std::setw(16) << std::left << "First Name:";
	std::cout << BOLD << pb.get_contact(i).get(first_name) << RESET << std::endl;
	std::cout << std::setw(16) << std::left << "Last Name:";
	std::cout << BOLD << pb.get_contact(i).get(last_name) << RESET << std::endl;
	std::cout << std::setw(16) << std::left << "Nick Name:";
	std::cout << BOLD << pb.get_contact(i).get(nick_name) << RESET << std::endl;
	std::cout << std::setw(16) << std::left << "Phone Number:";
	std::cout << BOLD << pb.get_contact(i).get(number) << RESET << std::endl;
	std::cout << std::setw(16) << std::left << "Darkest Secret:";
	std::cout << BOLD << pb.get_contact(i).get(secret) << RESET << std::endl;
}

static void display_array(PhoneBook pb, std::string error)
{
	std::cout << "🦑━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━🦑" << std::endl;
	std::cout << "┃  index   ┃first name┃ lastname ┃ nickname ┃" << std::endl;
	for (int i = 0; i < pb.get_index(); i++)
	{
		std::cout << "┃" << std::right << std::setw(10) << i << "┃";
		for (size_t j = 0; j < 3; j++)
		{
			std::string field = pb.get_contact(i).get(j);
			if (field.length() > 10)
				std::cout << field.substr(0, 9) << "."
						  << "┃";
			else
				std::cout << std::setw(10) << field << "┃";
		}
		std::cout << std::endl;
	}
	std::cout << "🦑━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━🦑" << std::endl << std::endl;
	std::cout << "Enter the" BOLD " index " RESET "of the contact you want to display" << std::endl;
	std::cout << error << "➜  ";
}

int search(PhoneBook pb)
{
	std::string to_show, error;

	if (!pb.get_index())
		return (std::cout << CLEAR << MAGENTA "                  Contacts" RESET << std::endl << std::endl
						  << MAGENTA "SquidBook" RESET " is empty, no contacts to display." << std::endl,
				press_enter());
	while (1)
	{		
		std::cout << CLEAR << MAGENTA "                  Contacts" RESET << std::endl;
		display_array(pb, error);
		std::getline(std::cin, to_show);
		if (std::cin.eof())
			return (-1);
		if ((to_show.empty() || is_only_whitespace(to_show)) && set_error(error, "can't be empty."))
			continue;
		if (to_show.size() > 1 && set_error(error, "enter only one character: the index."))
			continue;
		if (!isdigit(to_show.at(0)) && set_error(error, "not a digit."))
			continue;
		if (to_show[0] - '0' >= pb.get_index() && set_error(error, "no contact at this index."))
			continue;
		print_contact(pb, to_show[0] - '0');
		break;
	}
	return (press_enter());
}
