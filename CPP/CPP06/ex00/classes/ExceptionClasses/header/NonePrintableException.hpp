
#ifndef NONEPRINTABLEEXCEPTION_HPP

#define NONEPRINTABLEEXCEPTION_HPP

#include "../../../include/libs.hpp"

class NonePrintableException : public std::exception {
	public :
		NonePrintableException( void );
		~NonePrintableException( void) throw();
		virtual const char *what() const throw();
	private:
		std::string _msg;
};

#endif
