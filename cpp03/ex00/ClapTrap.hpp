#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cmath>
#define RESET "\x1B[0m"
#define RED "\x1B[1;31m"
#define GREEN "\x1B[1;32m"
#define YELLOW "\x1B[1;33m"
#define BLUE "\x1B[1;34m"
#define MAGENTA "\x1B[1;35m"
#define CYAN "\x1B[1;36m"
#define WHITE "\x1B[1;37m"
#define GRAY "\x1B[1;90m"
#define BOLD_WHITE "\x1B[1;97m"

class ClapTrap
{
public:
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void displayStats(void) const;

private:
	std::string _name;
	unsigned int _HPs;
	unsigned int _EPs;
	unsigned int _AD;
};

#endif