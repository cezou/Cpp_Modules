#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	Contact get_contact(int i) const;
	void set_contact(Contact contact, int i);
	int get_index() const;
	int increment_index();

private:
	Contact _contacts[8];
	int _index;
};

#define BOLD "\033[1m"
#define RED "\033[1;31m"
#define RRED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"
#define CLEAR "\x1b[2J\x1b[H"
#define HIDE_CURSOR "\x1b[?25l"
#define SHOW_CURSOR "\x1b[?25h"
#define UP "\033[1A"
#define ERASE "\033[0J"

inline std::string you_can_only()
{
	return (std::string("You can only ") + GREEN + "ADD" + RESET + ", " + BLUE + "SEARCH" + RESET + " and " + RED + "EXIT" + RESET + ".");
}

inline std::string commands()
{
	return (std::string(GREEN "ADD") + RESET + ", " + BLUE + "SEARCH" + RESET + " and " + RED + "EXIT" + RESET + ".");
}

/* Utils */
void display(std::string error);
bool is_empty(const std::string &s);
bool is_only_whitespace(const std::string &s);
std::string remove_whitespaces(const std::string &s);

int search(PhoneBook pb);
int add(PhoneBook *pb);
bool set_error(std::string &error, std::string message);

#endif
