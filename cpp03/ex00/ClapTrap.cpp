#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) : _name(name), _HPs(10), _EPs(10), _AD(0)
{
	std::cout << name << " spawned!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " died!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->_EPs || !this->_HPs)
		return;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_AD << "points of damage !" << std::endl;
	this->_EPs--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_HPs)
		return;
	if (amount > this->_HPs)
	{
		std::cout << "ClapTrap " << this->_name << " lost " << this->_HPs << "points of damage !" << std::endl;
		this->_HPs = 0;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " lost " << amount << "points of damage !" << std::endl;
	this->_HPs -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HPs && this->_EPs)
	{
		std::cout << "ClapTrap " << this->_name << " got " << amount << " HPs back!" << std::endl;
		this->_HPs += amount;
		this->_EPs--;
	}
}