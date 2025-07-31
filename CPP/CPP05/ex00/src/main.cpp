#include "../include/includes.hpp"

int main(void) {
	try {
		std::cout << "\n--- Creating Bureaucrat with name 'John' and grade 3 ---" << std::endl;
		Bureaucrat john("John", 3);
		std::cout << john;
		std::cout << "\n--- Incrementing John's grade ---" << std::endl;
		john.increment();
		std::cout << john;
		std::cout << "\n--- Decrementing John's grade ---" << std::endl;
		john.decrement();
		std::cout << john;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Creating Bureaucrat with an invalid grade (151) ---" << std::endl;
		Bureaucrat tooLow("TooLow", 151);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Creating Bureaucrat with an invalid grade (0) ---" << std::endl;
		Bureaucrat tooHigh("TooHigh", 0);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Creating Bureaucrat with grade 150 and attempting to decrement ---" << std::endl;
		Bureaucrat low("Low", 150);
		std::cout << low;
		low.decrement();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Creating Bureaucrat with grade 1 and attempting to increment ---" << std::endl;
		Bureaucrat high("High", 1);
		std::cout << high;
		high.increment();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
