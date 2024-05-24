#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "The program takes one argument" << std::endl, 1);
	std::string level = av[1];
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
		return (std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl, 1);
	Harl harl;
	harl.complain(av[1]);
}