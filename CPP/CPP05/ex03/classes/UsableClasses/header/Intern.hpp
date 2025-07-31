#ifndef INTERN_HPP

#define INTERN_HPP

#include "../../../include/libs.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class Intern {
	private:

	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		AForm *makeForm(std::string name, std::string target);
};

#endif
