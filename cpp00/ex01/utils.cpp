#include "PhoneBook.hpp"

void display(std::string error)
{
	std::cout << CLEAR;
	std::cout << MAGENTA "       🦑 SquidBook 🦑" RESET << std::endl
			  << std::endl;
	std::cout << you_can_only() << std::endl;
	std::cout << error << "➜  ";
}

bool is_empty(const std::string &s)
{
	return (s.empty() || s.find_first_not_of(" \t\n\r\f\v") == std::string::npos);
}

bool is_only_whitespace(const std::string &s)
{
	return (s.find_first_not_of(' ') == std::string::npos);
}

std::string remove_whitespaces(const std::string &s)
{
	std::string ws = " \t\n\r\f\v";
	size_t start = s.find_first_not_of(ws), end = s.find_last_not_of(ws);

	return (s.substr(start, end - start + 1));
}

bool set_error(std::string &error, std::string message)
{
	error = RED "ERROR: " RESET RRED + message + "\n" RESET;
	return (1);
}
