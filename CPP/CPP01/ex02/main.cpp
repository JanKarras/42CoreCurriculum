#include <string>
#include <iostream>

int	main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "This is the adress of the string " << &string << std::endl;
	std::cout << "This is the adress of the pointer " << stringPTR << std::endl;
	std::cout << "This is the adress of the reference " << &stringREF << std::endl;
	std::cout << "This is the value of the string " << string << std::endl;
	std::cout << "This is the value of the pointer " << *stringPTR << std::endl;
	std::cout << "This is the value of the reference " << stringREF << std::endl;
	return (0);
}
