#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string name) : _name(name), _HPs(10), _EPs(10), _AD(0)
{
	std::cout << WHITE << name << RESET << " spawned!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _HPs(other._HPs), _EPs(other._EPs), _AD(other._AD)
{
	std::cout << WHITE << other._name << RESET << " copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_HPs = other._HPs;
		this->_EPs = other._EPs;
		this->_AD = other._AD;
		std::cout << WHITE << other._name << RESET << " assigned!" << std::endl;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << WHITE << this->_name << RESET << " died!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->_EPs)
	{
		std::cout << "ClapTrap " << WHITE << this->_name << RESET << " is out of energy, he can't attack!" << std::endl;
		return;
	}
	if (!this->_HPs)
	{
		std::cout << "ClapTrap " << WHITE << this->_name << RESET << " is dead, he can't attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << WHITE << this->_name << RESET << " attacks " << WHITE << target << RESET << " causing " << GRAY << this->_AD << RESET << " points of damage!" << std::endl;
	this->_EPs--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_HPs)
	{
		std::cout << "ClapTrap " << WHITE << this->_name << RESET << " is already dead, he can't take damage!" << std::endl;
		return;
	}
	if (amount > this->_HPs)
	{
		std::cout << "ClapTrap " << WHITE << this->_name << RESET << " lost " << this->_HPs << " points of damage!" << std::endl;
		this->_HPs = 0;
		return;
	}
	std::cout << "ClapTrap " << WHITE << this->_name << RESET << " lost " << GRAY << amount << RESET << " points of damage!" << std::endl;
	this->_HPs -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_EPs)
	{
		std::cout << "ClapTrap " << WHITE << this->_name << RESET << " is out of energy, he can't repair himself!" << std::endl;
		return;
	}
	if (!this->_HPs)
	{
		std::cout << "ClapTrap " << WHITE << this->_name << RESET << " is dead, he can't repair himself!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << WHITE << this->_name << RESET << " got " << GREEN << amount << RESET << " HPs back!" << std::endl;
	this->_HPs += amount;
	this->_EPs--;
}

void ClapTrap::displayStats(void) const
{
	std::cout << "ClapTrap " << WHITE << this->_name << RESET << " has " << GREEN << this->_HPs << RESET << " HPs, " << BLUE << this->_EPs << RESET << " EPs and " << GRAY << this->_AD << RESET << " AD." << std::endl;
}