#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	this->_brain = new Brain();
	std::cout << GREEN << "Default Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_brain = new Brain(*(other._brain));
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*(other._brain));
		std::cout << GREEN << "Cat copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << RED << "Default Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	// Animal::makeSound();
	std::cout << "MIAOUUUUUU" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return _brain->getIdea(index);
	return "";
}
