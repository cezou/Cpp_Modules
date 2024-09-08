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
	if (this != &copy)
	{
		const_cast<Fixed &>(this->_x) = copy._x;
		const_cast<Fixed &>(this->_y) = copy._y;
	}
	return *this;
}

Fixed Point::getX() const
{
	return this->_x;
}

Fixed Point::getY() const
{
	return this->_y;
}
