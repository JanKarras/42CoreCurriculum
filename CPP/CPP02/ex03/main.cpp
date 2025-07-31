/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:00:48 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:00:48 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include "Point.h"

int main( void ) {
	Point A (0, 0);
	Point B (4, 0);
	Point C (2, 4);

	std::cout << "Dreieck: A(0, 0), B(4, 0), C(2, 4)\n";
	Point tests[] = {
		Point(-1, 5),
		Point(5, 5),
		Point(2, -1),
		Point(0, 0),
		Point(4, 0),
		Point(2, 4),
		Point(2, 2),
		Point(1, 0),
		Point(3, 2),
		Point(1, 2),
		Point(2, 0.1),
		Point(3, 1.9),
		Point(0.1, 0.1)
	};
	bool expected[] = {
		false, false, false,
		true, true, true,
		true, true, true,
		true, true, true, true
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
