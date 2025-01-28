#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << WHITE << name << RESET << " FragTrap spawned!" << std::endl;
	this->_HPs = 100;
	this->_fragHPs = this->_HPs;
	this->_EPs = 100;
	this->_AD = 30;
	this->_fragAD = this->_AD;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << WHITE << other._name << RESET << " FragTrap copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_fragAD = other._fragAD;
		this->_fragHPs = other._fragHPs;
		std::cout << WHITE << other._name << RESET << " FragTrap assigned!" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << WHITE << this->_name << RESET << " FragTrap died!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << WHITE << this->_name << RESET << RED " wants to HIGH FIVE!" RESET << std::endl;
}

unsigned int FragTrap::getAD(void) const
{
	return this->_fragAD;
}

unsigned int FragTrap::getHPs(void) const
{
	return this->_fragHPs;
}