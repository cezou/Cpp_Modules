#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>

class Fixed
{

public:
	Fixed();
	Fixed(Fixed copy);
	~Fixed();

private:
	int _integer;
	static const int frac = 8;
};

#endif