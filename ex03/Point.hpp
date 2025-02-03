#include "Fixed.hpp"

class Point
{
private:
	Fixed x;
	Fixed y;
public:
	Point();
	Point(float x, float y);
	Point(const Point&);
	~Point();
	Point& operator=(const Point& other);
	bool bsp( Point const a, Point const b, Point const c, Point const point);
	Fixed getX() const;
	Fixed getY() const;
};
