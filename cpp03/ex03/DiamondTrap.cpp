#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << WHITE << name << RESET << " DiamondTrap spawned!" << std::endl;
	this->_HPs = getHPs();
	this->_EPs = getEPs();
	this->_AD = getAD();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << WHITE << other._name << RESET << " DiamondTrap copied!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
		std::cout << WHITE << other._name << RESET << " DiamondTrap assigned!" << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << WHITE << this->_name << RESET << " DiamondTrap died!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: "
			  << WHITE << this->_name << RESET
			  << ", ClapTrap name : " << WHITE
			  << ClapTrap::_name << RESET << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::displayStats(void) const
{
	std::cout << "DiamondTrap " << WHITE << this->_name << RESET << " has " << GREEN << this->_HPs << RESET << " HPs, " << BLUE << this->_EPs << RESET << " EPs and " << GRAY << this->_AD << RESET << " AD." << std::endl;
}