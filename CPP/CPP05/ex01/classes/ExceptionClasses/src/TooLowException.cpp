#include "../header/TooLowException.hpp"

TooLowException::TooLowException( void ) : message("Grade is to low!") {
	if(DEBUG) {
		std::cout << "TooLowException default constructor called\n";
	}
}

TooLowException::~TooLowException( void ) throw() {
	if(DEBUG) {
		std::cout << "TooLowException default deconstructor called\n";
	}
}

const char *TooLowException::what() const throw() {
	return (message.c_str());
}
