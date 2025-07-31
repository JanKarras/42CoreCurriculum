#ifndef EXECUTEUNSIGNEDEXCEPTION_HPP

#define EXECUTEUNSIGNEDEXCEPTION_HPP

#include "../../../include/libs.hpp"

class ExecuteUnsignedException : public std::exception {
	private:
		std::string messege;
	public:
		ExecuteUnsignedException( void );
		~ExecuteUnsignedException() throw();
		virtual const char *what() const throw();
};

#endif
