#ifndef TOOHIGHEXPETION_HPP

#define TOOHIGHEXPETION_HPP

#include "../../../include/includes.hpp"

class TooHighException : public std::exception {
	private:
		std::string message;
	public:
		TooHighException( void );
		~TooHighException() throw();
		virtual const char *what() const throw();
};

#endif
