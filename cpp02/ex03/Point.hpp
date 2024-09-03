#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cmath>
#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Point &p);
	Point(const float x, const float y);
	~Point();
	Point &operator=(const Point &copy);

	Fixed getX() const;
	Fixed getY();
	void setX(Fixed &x);
	void setY(Fixed y);

private:
	const Fixed _x;
	const Fixed _y;
};

#endif