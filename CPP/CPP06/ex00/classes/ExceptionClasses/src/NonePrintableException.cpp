#include "../header/NonePrintableException.hpp"

NonePrintableException::NonePrintableException( void ) : _msg("non displayable characters detected\n") {
	if (DEBUG) {
		std::cout << "NonePrintableException default constructor called\n";
	}
}

NonePrintableException::~NonePrintableException( void ) throw() {
	if (DEBUG) {
		std::cout << "NonePrintableException default destructor called\n";
	}
}

const char *NonePrintableException::what( void ) const throw() {
	return (_msg.c_str());
}
