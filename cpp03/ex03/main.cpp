#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap c("Pierre Chabrier");
	ScavTrap s("Sylvain Lyve");
	FragTrap f("Frag");
	DiamondTrap d("Diamond");

	d.displayStats();
	d.whoAmI();
	c.displayStats();
	s.displayStats();
	f.displayStats();
	c.attack("Sylvain Lyve");
	s.attack("Pierre Chabrier");
	f.attack("Pierre Chabrier");
	d.attack("Sylvain Lyve");

	c.takeDamage(5);
	s.takeDamage(5);
	f.takeDamage(5);
	d.takeDamage(5);
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();

	return 0;
}