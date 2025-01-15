#include "Fixed.hpp"
#include "Point.hpp"


int main ( void ) {
	{
		Point a(7 , 3);
		Point b (2 , 6);
		Point c (1 , 5);
		
		// // Puntos fuera del triangulo
		// Point p1(0, 0);  // Muy lejos, fuera del área del triángulo
        // Point p2(8, 7);  // Al exterior, más allá de los límites de los vértices
        // Point p3(3, 7);  // Arriba y fuera del triángulo
        // Point p4(7, 2);  // Cerca de un vértice, pero fuera del triángulo
        // Point p5(1, 4);  // Muy cerca de un lado, pero fuera


        // Puntos dentro del triángulo
        Point p1(3, 5);  // Cerca del lado b -> c
        Point p2(5, 4);  // Cerca del centro del triángulo
        Point p3(6, 4);  // Cerca del lado a -> b
        Point p4(2.5, 5.5);  // Cerca del vértice b
        Point p5(4, 5);  // Cerca del lado a -> c

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