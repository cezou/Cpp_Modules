#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
	std::cout << GREEN << "Default Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
		std::cout << GREEN << "Brain copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << RED << "Default Brain destructor called" << RESET << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return _ideas[index];
	return "";
}
