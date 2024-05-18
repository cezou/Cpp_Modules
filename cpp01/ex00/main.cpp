#include "Zombie.hpp"

int main(void)
{
	Zombie *zomb = newZombie(MAGENTA "Squid" RESET);
	zomb->announce();
	randomChump(BLUE "Game" RESET);
	delete zomb;
}