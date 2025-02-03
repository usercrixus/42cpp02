#include "Point.hpp"

int main( void ) {
	Point a(0, 0);
	Point b(0, 1);
	Point c(1, 0);
	Point d(0.5, 0.5);
	Point e(2, 2);

	std::cout << "is d in abc: " << a.bsp(a, b ,c, d) << std::endl;
	std::cout << "is e in abc: " << a.bsp(a, b ,c, e) << std::endl;

	return 0;
}