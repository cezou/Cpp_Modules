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

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	Fixed &operator=(const Fixed &copy);
	Fixed operator*(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator+(const Fixed &other);
	Fixed operator/(const Fixed &other);

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;

private:
	int _integer;
	static const int frac = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

bool is_float(const Fixed &fixed);

#endif