#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << WHITE << name << RESET << " ScavTrap spawned!" << std::endl;
	this->_HPs = 100;
	this->_EPs = 50;
	this->_AD = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << WHITE << this->_name << RESET << " ScavTrap died!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << WHITE << this->_name << RESET << YELLOW " is now in Gate keeper mode." RESET << std::endl;
}
