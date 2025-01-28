#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << GREEN << "Default Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << GREEN << "Dog copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << RED << "Default Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}