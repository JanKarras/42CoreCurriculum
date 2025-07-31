#include "../header/TooHighException.hpp"

TooHighException::TooHighException( void ) : message("Grade is to high!") {
	if(DEBUG) {
		std::cout << "TooHighException default constructor called\n";
	}
}

TooHighException::~TooHighException( void ) throw() {
	if(DEBUG) {
		std::cout << "TooHighException default deconstructor called\n";
	}
}

const char *TooHighException::what() const throw() {
	return (message.c_str());
}

