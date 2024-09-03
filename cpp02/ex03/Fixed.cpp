#include "Fixed.hpp"

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_integer) / (1 << this->frac);
}

int Fixed::toInt(void) const
{
	return this->_integer >> this->frac;
}

int Fixed::getRawBits() const
{
	return this->_integer;
}

void Fixed::setRawBits(int const raw)
{
	this->_integer = raw;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	this->setRawBits(copy._integer);
	return *this;
}

bool is_float(const Fixed &fixed)
{
	return (fixed.toInt() != fixed.getRawBits());
}

// Arithmetic operators

Fixed Fixed::operator*(const Fixed &other)
{
	if (is_float(*this) && is_float(other))
		return Fixed(this->toFloat() * other.toFloat());
	if (is_float(*this) && !is_float(other))
		return Fixed(this->toFloat() * other.toInt());
	if (is_float(other))
		return Fixed(this->toInt() * other.toFloat());
	return Fixed(this->toInt() * other.toInt());
}

Fixed Fixed::operator-(const Fixed &other)
{
	if (is_float(*this) && is_float(other))
		return Fixed(this->toFloat() - other.toFloat());
	if (is_float(*this) && !is_float(other))
		return Fixed(this->toFloat() - other.toInt());
	if (is_float(other))
		return Fixed(this->toInt() - other.toFloat());
	return Fixed(this->toInt() - other.toInt());
}

Fixed Fixed::operator+(const Fixed &other)
{
	if (is_float(*this) && is_float(other))
		return Fixed(this->toFloat() + other.toFloat());
	if (is_float(*this) && !is_float(other))
		return Fixed(this->toFloat() + other.toInt());
	if (is_float(other))
		return Fixed(this->toInt() + other.toFloat());
	return Fixed(this->toInt() + other.toInt());
}

Fixed Fixed::operator/(const Fixed &other)
{
	if (other.getRawBits() == 0)
		return (std::cout << "Can't divide by zero." << std::endl, *this);
	if (is_float(*this) && is_float(other))
		return Fixed(this->toFloat() / other.toFloat());
	if (is_float(*this) && !is_float(other))
		return Fixed(this->toFloat() / other.toInt());
	if (is_float(other))
		return Fixed(this->toInt() / other.toFloat());
	return Fixed(this->toInt() / other.toInt());
}

// Comparaison operators

bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

// Insertion operator

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

// Increment operators.

Fixed &Fixed::operator++()
{
	this->_integer++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_integer++;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->_integer--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_integer--;
	return temp;
}

// Constructors

Fixed::Fixed() : _integer(0)
{
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}
Fixed::Fixed(const int number)
{
	this->_integer = number << this->frac;
}

Fixed::Fixed(const float number)
{
	this->_integer = number * (1 << this->frac);
}

Fixed::~Fixed()
{
}
