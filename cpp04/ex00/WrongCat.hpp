#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cmath>
#define RESET "\x1B[0m"
#define RED "\x1B[1;31m"
#define GREEN "\x1B[1;32m"
#define YELLOW "\x1B[1;33m"
#define BLUE "\x1B[1;34m"
#define MAGENTA "\x1B[1;35m"
#define CYAN "\x1B[1;36m"
#define WHITE "\x1B[1;37m"
#define GRAY "\x1B[1;90m"
#define BOLD_WHITE "\x1B[1;97m"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	~WrongCat();
	void makeSound() const;
};

#endif