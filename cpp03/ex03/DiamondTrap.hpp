#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(const std::string name);
	~DiamondTrap();
	void whoAmI();

private:
	std::string _diamondName;
};

#endif