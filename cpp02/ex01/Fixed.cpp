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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_integer;
}

void Fixed::setRawBits(int const raw)
{
	this->_integer = raw;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(copy._integer);
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

// Constructors

Fixed::Fixed() : _integer(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}
Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_integer = number << this->frac;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_integer = number * (1 << this->frac);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}