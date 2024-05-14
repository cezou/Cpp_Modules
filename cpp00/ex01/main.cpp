#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb; 
	std::string command, error;

	while (1)
	{
		display(error); std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command != "ADD" && command != "SEARCH" && command != "EXIT" && set_error(error, "different from ADD, SEARCH or EXIT"))
			continue;
		if (command == "ADD")
		{
			if (add(&pb) == -1)
				break;
		}
		else if (command == "SEARCH")
		{
			if (search(pb) == -1)
				break;
		} 
		else
			break;
		error = "";
	}
	std::cout << CLEAR;
}
