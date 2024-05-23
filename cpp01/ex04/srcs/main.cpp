#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <fstream>

void replace(std::ifstream &file, std::string filename, std::string s1, std::string s2)
{
	std::ofstream newfile((filename + ".replace").c_str());
	if (!newfile)
		return ((void)(std::cerr << "Unable to create file " << filename + ".replace" << std::endl));
	std::string line;
	while (std::getline(file, line))
	{
		line += '\n';
		size_t pos;
		while ((pos = line.find(s1)) != std::string::npos)
		{
			newfile << line.substr(0, pos);
			newfile << s2;
			line.erase(0, pos + s1.length());
		}
		newfile << line;
	}
	newfile.close();
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