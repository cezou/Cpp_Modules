#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point a(0, 0);
	Point b(0, 9);
	Point c(9, 4.5f);
	Point p(1, 8);

	print_graph(a, b, c, p);
	bsp(a, b, c, p) ? std::cout << "Point is Inside!\n"
					: std::cout << "Point is Outside!\n";
	return 0;
}