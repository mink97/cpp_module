#include "Point.hpp"

int main( void ) {
	Point	a(1, 2);
	Point	b(0, 0);
	Point	c(2, 0);
	Point	point(2, 2);

	std::cout << std::boolalpha << bsp(a, b, c, point) << std::endl;
	return 0;
}
