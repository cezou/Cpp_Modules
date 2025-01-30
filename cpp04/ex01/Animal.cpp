#include "Animal.hpp"

Animal::Animal()
{
	std::cout << GREEN << "Default Animal constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << GREEN << "Animal copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << RED << "Default Animal destructor called" << RESET << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << "I am an Animal, I don't know what sound to do." << std::endl;
}
