#include "../header/AlreadySigendException.hpp"

AlreadySigendException::AlreadySigendException( void ) : messege("Form is already sigend") {

}

AlreadySigendException::~AlreadySigendException( void ) throw() {

}

const char *AlreadySigendException::what() const throw() {
	return (messege.c_str());
}
