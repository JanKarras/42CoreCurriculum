#ifndef TOOLOWException_HPP

#define TOOLOWException_HPP

#include "../../../include/libs.hpp"

class TooLowException : public std::exception {
	private:
		std::string message;
	public:
		TooLowException( void );
		~TooLowException() throw();
		virtual const char *what() const throw();
};

#endif
