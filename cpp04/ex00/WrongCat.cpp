#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << GREEN << "Default WrongCat constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << GREEN << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		std::cout << GREEN << "WrongCat copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "Default WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "MIAOUUUUUU" << std::endl;
}
