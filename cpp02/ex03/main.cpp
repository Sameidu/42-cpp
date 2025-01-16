#include "Fixed.hpp"
#include "Point.hpp"


int main ( void ) {
	{
		Point a(0 , 0);
		Point b (0 , 10);
		Point c (10 , 0);

		// Puntos dentro del triangulo
		Point p1 (1, 1);
		Point p2 (5, 5);
		Point p3 (1, 5);
		Point p4 (5, 1);
		Point p5 (3, 3);

		// // Puntos fuera del triangulo
		// Point p1 (11, 11);
		// Point p2 (11, 5);
		// Point p3 (5, 11);
		// Point p4 (-1, -1);
		// Point p5 (-1, 5);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		std::cout << "P1: " << p1 << " -> " << bsp(a, b, c, p1) << std::endl;
        std::cout << "P2: " << p2 << " -> " << bsp(a, b, c, p2) << std::endl;
        std::cout << "P3: " << p3 << " -> " << bsp(a, b, c, p3) << std::endl;
        std::cout << "P4: " << p4 << " -> " << bsp(a, b, c, p4) << std::endl;
        std::cout << "P5: " << p5 << " -> " << bsp(a, b, c, p5) << std::endl;
	}
	return 0;
}