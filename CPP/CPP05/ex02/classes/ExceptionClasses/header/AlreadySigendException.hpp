#ifndef ALREADYSIGENDEXCEPTION_HPP

#define ALREADYSIGENDEXCEPTION_HPP

#include "../../../include/libs.hpp"

class AlreadySigendException : public std::exception {
	private:
		std::string messege;
	public:
		AlreadySigendException( void );
		~AlreadySigendException() throw();
		virtual const char *what() const throw();
};

#endif
