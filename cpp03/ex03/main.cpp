#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap a("Pierre Chabrier");
	ScavTrap b("Sylvain Lyve");
	DiamondTrap c("Diamond");

	a.displayStats();
	b.displayStats();
	c.displayStats();

	a.attack("Sylvain Lyve");
	b.takeDamage(1);
	b.displayStats();

	b.beRepaired(1);
	b.displayStats();

	b.takeDamage(10);
	b.displayStats();

	b.beRepaired(1);
	b.displayStats();

	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.displayStats();

	a.attack("Sylvain Lyve");
	a.beRepaired(1);

	b.guardGate();
	c.whoAmI();

	return 0;
}