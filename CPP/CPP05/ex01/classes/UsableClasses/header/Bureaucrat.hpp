#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP

#include "../../../include/includes.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat( void );
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		std::string const &getName( void ) const;
		int getGrade( void ) const;
		void increment( void );
		void decrement( void );
		void signForm(Form &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
