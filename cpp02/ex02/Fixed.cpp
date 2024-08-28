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
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_integer;
}

void Fixed::setRawBits(int const raw)
{
	this->_integer = raw;
}

int &Fixed::min(int &a, int &b)
{
	return (a < b ? a : b);
}

const int &Fixed::min(const int &a, const int &b)
{
	return (a < b ? a : b);
}

int &Fixed::max(int &a, int &b)
{
	return (a > b ? a : b);
}

const int &Fixed::max(const int &a, const int &b)
{
	return (a > b ? a : b);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(copy._integer);
	return *this;
}

Fixed &Fixed::operator*(const Fixed &other)
{
	this->setRawBits(this->toFloat() * other.toFloat());
	return *this;
}

bool Fixed::operator>(const Fixed &other)
{
	return (this->getRawBits() > other.getRawBits());
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

// Constructors

Fixed::Fixed() : _integer(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}
Fixed::Fixed(const int number)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_integer = number << this->frac;
}

Fixed::Fixed(const float number)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_integer = number * (1 << this->frac);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}