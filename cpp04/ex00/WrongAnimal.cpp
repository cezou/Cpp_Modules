#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "Default WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << GREEN << "WrongAnimal copy constructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << GREEN << "WrongAnimal copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "Default WrongAnimal destructor called" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "I am an Animal, I don't know what sound to do." << std::endl;
}
