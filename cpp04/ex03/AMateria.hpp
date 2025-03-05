#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
public:
	// Constructors
	AMateria();
	AMateria(const AMateria &copy);

	// Destructor
	~AMateria();

	// Operators
	AMateria &operator=(const AMateria &assign);

private:
};

#endif