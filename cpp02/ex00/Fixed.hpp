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
	Fixed(const Fixed &fixed);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
	Fixed &operator=(const Fixed &copy);

private:
	int _integer;
	static const int frac = 8;
};

#endif