#include "../include/Span.hpp"

int main( void ) {
	Span span(15);

	std::srand(time(0));
	for (size_t i = 0; i < 10; i++) {
		span.addNumber(i);
	}
	span.addNumber(-20);
	span.addNumber(-10);
	span.addNumber(50);
	span.addNumber(-1);
	span.addNumber(50);
	//std::cout << span << std::endl;
	try {
		span.addNumber(15);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << "Longest Span: " << span.longesSpan() << std::endl;
	std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
	Span bigSpan(1000000);
	for (size_t i = 0; i < 1000000; i++) {
		bigSpan.addNumber(i);
	}
	//std::cout << bigSpan << std::endl;
	try {
		span.addNumber(15);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << "Longest Span: " << bigSpan.longesSpan() << std::endl;
	std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
	Span bigSpamRand(1000000);
	for (size_t i = 0; i < 1000000; i++) {
		static std::set<int> uniqueNumbers;
		int newRand = rand();
		if (uniqueNumbers.insert(newRand).second) {
			bigSpamRand.addNumber(newRand);
		}
	}
	//std::cout << bigSpamRand << std::endl;
	std::cout << "Longest Span: " << bigSpamRand.longesSpan() << std::endl;
	std::cout << "Shortest Span: " << bigSpamRand.shortestSpan() << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longesSpan() << std::endl;

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(70);
	vec.push_back(-80);
	vec.push_back(46);
	Span toSmallNumbers(4);
	try {
		toSmallNumbers.addRange(vec.begin(), vec.end());
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Span Numbers(5);
	Numbers.addRange(vec.begin(), vec.end());
	std::cout << Numbers << std::endl;
	return (0);
}
