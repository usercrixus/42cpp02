#include "Point.hpp"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point &original) : x(original.x), y(original.y)
{
}
Point::~Point()
{
}

Point& Point::operator=(const Point& other)
{
    if (this != &other)
	{
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

static Fixed absolute(Fixed value)
{
    return (value < Fixed(0)) ? value * -1 : value;
}

static Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
    return absolute(
        (p1.getX() * (p2.getY() - p3.getY())) +
        (p2.getX() * (p3.getY() - p1.getY())) +
        (p3.getX() * (p1.getY() - p2.getY()))
    ) / Fixed(2);
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Compute the full triangle's area
    Fixed fullArea = area(a, b, c);

    // Compute the sub-triangle areas
    Fixed area1 = area(point, a, b);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(point, c, a);

    // Check if the sum of sub-areas is equal to the total area
    return (fullArea == (area1 + area2 + area3));
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}
