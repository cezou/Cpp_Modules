#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _diamondName(name)
{
	std::cout << WHITE << name << RESET << " DiamondTrap spawned!" << std::endl;
	this->_HPs = FragTrap::_HPs;
	this->_EPs = ScavTrap::_EPs;
	this->_AD = FragTrap::_AD;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << WHITE << this->_diamondName << RESET << " DiamondTrap died!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << WHITE << this->_diamondName << RESET << ", ClapTrap name: " << WHITE << ClapTrap::_name << RESET << std::endl;
}