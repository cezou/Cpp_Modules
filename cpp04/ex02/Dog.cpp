#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << GREEN << "Default Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->_brain = new Brain(*(other._brain));
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*(other._brain));
		std::cout << GREEN << "Dog copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << RED << "Default Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return _brain->getIdea(index);
	return "";
}