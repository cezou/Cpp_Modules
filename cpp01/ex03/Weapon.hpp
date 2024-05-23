#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>

class Weapon
{
public:
	Weapon(std::string type);
	const std::string &getType(void) const;
	void setType(std::string type);

private:
	std::string _type;
};

#endif