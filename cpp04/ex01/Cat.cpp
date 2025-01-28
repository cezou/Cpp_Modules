#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << GREEN << "Default Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << GREEN << "Cat copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << RED << "Default Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MIAOUUUUUU" << std::endl;
}
