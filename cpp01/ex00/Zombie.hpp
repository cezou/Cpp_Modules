#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cctype>

class Zombie
{
public:
	Zombie(std::string name);
	void announce(void);
	~Zombie();

private:
	std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

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
#endif