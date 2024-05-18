#include "Zombie.hpp"

int main(void)
{
	Zombie *horde = zombieHorde(5, MAGENTA "Zombie" RESET);
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
}