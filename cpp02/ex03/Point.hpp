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
	Fixed getY() const;

private:
	const Fixed _x;
	const Fixed _y;
};

void print_graph(Point const a, Point const b, Point const c, Point const point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif