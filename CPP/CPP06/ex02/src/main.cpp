/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:26:25 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:26:25 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libs.hpp"
#include "../classes/UsableClasses/header/Base.hpp"

Base *generate( void) {
	int choice = std::rand() % 3;
	Base *p;
	std::cout << choice << std::endl;
	switch (choice) {
	case 0:
		p = new A();
		break;
	case 1:
		p = new B();
		break;
	case 2:
		p = new C();
		break;
	default:
		p = NULL;
		break;
	}
	return (p);
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "A\n";
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "B\n";
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "C\n";
	} else {
		std::cout << "unknown";
	}
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A\n";
	} catch(const std::exception& e) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "B\n";
		} catch(const std::exception& e) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "C\n";
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int main(void) {
	Base *p;

	srand(time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		p = generate();
		identify(p);
		identify(*p);
		delete p;
	}
	return (0);
}
