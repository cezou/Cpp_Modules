#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << WHITE << name << RESET << " ScavTrap spawned!" << std::endl;
	this->_HPs = 100;
	this->_EPs = 50;
	this->_scavEPs = this->_EPs;
	this->_AD = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << WHITE << other._name << RESET << " ScavTrap copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_scavEPs = other._scavEPs;
		std::cout << WHITE << other._name << RESET << " ScavTrap assigned!" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << WHITE << this->_name << RESET << " ScavTrap died!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << WHITE << this->_name << RESET << YELLOW " is now in Gate keeper mode." RESET << std::endl;
}

unsigned int ScavTrap::getEPs(void) const
{
	return this->_scavEPs;
}
