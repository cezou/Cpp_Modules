#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <fstream>

void replace(std::ifstream &file, std::string filename, std::string s1, std::string s2)
{
	// Create a new file with the filename + ".replace"
	std::ofstream newfile(filename + ".replace");
	if (!newfile)
		return ((void)(std::cerr << "Unable to create file " << filename + ".replace" << std::endl));
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cerr << "The program takes 3 parameters" << std::endl, 1);
	std::ifstream file(av[1]);
	if (!file)
		return (std::cerr << "Unable to open file " << av[1] << std::endl, 1);
	replace(file, av[1], av[2], av[3]);
	file.close();
}