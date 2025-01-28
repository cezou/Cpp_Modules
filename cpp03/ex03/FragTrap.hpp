#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	virtual ~FragTrap();
	void highFivesGuys();
	unsigned int getAD(void) const;
	unsigned int getHPs(void) const;

private:
	unsigned int _fragAD;
	unsigned int _fragHPs;
};

#endif
