#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}
Point::Point(const Point &p)
{
	*this = p;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &copy)
{
	this->setX(copy.getX());
	return *this;
}

Fixed Point::getX() const
{
	return this->_x;
}

Fixed Point::getY()
{
	return this->_y;
}

void Point::setX(const Fixed &x)
{
	this->_x = x;
}

void Point::setY(Fixed y)
{
	this->_y = y;
}