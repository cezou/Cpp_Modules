#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cmath>

class Fixed
{

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int number);
	Fixed(const float number);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static int &min(int &a, int &b);
	static const int &min(const int &a, const int &b);
	static int &max(int &a, int &b);
	static const int &max(const int &a, const int &b);

	Fixed &operator=(const Fixed &copy);
	Fixed &operator*(const Fixed &other);

	bool operator>(const Fixed &other);

private:
	int _integer;
	static const int frac = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif