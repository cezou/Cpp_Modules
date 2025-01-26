#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << WHITE << name << RESET << " FragTrap spawned!" << std::endl;
	this->_HPs = 100;
	this->_EPs = 100;
	this->_AD = 30;
}

FragTrap::~FragTrap()
{
	std::cout << WHITE << this->_name << RESET << " FragTrap died!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << WHITE << this->_name << RESET << RED " wants to HIGH FIVE!" RESET << std::endl;
}
