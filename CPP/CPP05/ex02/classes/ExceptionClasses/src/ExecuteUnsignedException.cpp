#include "../header/ExecuteUnsignedException.hpp"

ExecuteUnsignedException::ExecuteUnsignedException( void ) : messege("Form ist unsigned") {

}

ExecuteUnsignedException::~ExecuteUnsignedException( void ) throw() {

}

const char *ExecuteUnsignedException::what() const throw() {
	return (messege.c_str());
}
