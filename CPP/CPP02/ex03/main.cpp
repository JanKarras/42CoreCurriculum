#include "Fixed.h"
#include "Point.h"

int main( void ) {
	Point A (0, 0);
	Point B (4, 0);
	Point C (2, 4);

	std::cout << "Dreieck: A(0, 0), B(4, 0), C(2, 4)\n";
	Point tests[] = {
		Point(-1, 5),  // Oben links (außerhalb)
		Point(5, 5),   // Oben rechts (außerhalb)
		Point(2, -1),  // Unten (außerhalb)
		Point(0, 0),   // Auf Ecke A
		Point(4, 0),   // Auf Ecke B
		Point(2, 4),   // Auf Ecke C
		Point(2, 2),   // Innerhalb des Dreiecks
		Point(1, 0),   // Auf Kante AB
		Point(3, 2),   // Auf Kante BC
		Point(1, 2),   // Auf Kante AC
		Point(2, 0.1), // Innerhalb, nah an Kante AB
		Point(3, 1.9), // Innerhalb, nah an Kante BC
		Point(0.1, 0.1) // Innerhalb, nah an Kante AC
	};
	bool expected[] = {
		false, false, false, // Tests außerhalb
		true, true, true,    // Tests auf Ecken
		true, true, true,    // Tests auf Kanten
		true, true, true, true     // Tests innerhalb, nahe Kanten
	};
	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
		std::cout << "Test " << i + 1 << ": Punkt ("
					<< tests[i].getX() << ", "
					<< tests[i].getY() << ") -> Erwartet: "
					<< (expected[i] ? "inside" : "outside")
					<< ", Ergebnis: ";
		bool result = bsp(A, B, C, tests[i]);
		std::cout << (result ? "inside" : "outside") << "\n";
		if (result != expected[i]) {
			std::cout << "  -> Fehler: Ergebnis entspricht nicht der Erwartung!\n";
		}
	}
	return 0;
}
