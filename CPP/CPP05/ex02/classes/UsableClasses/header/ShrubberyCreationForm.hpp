#ifndef SHRUBBERYCREATIONFORM_HPP

#define SHRUBBERYCREATIONFORM_HPP

#include "../../../include/libs.hpp"
#include "../../AbstractClasses/header/AForm.hpp"
#include "../../ExceptionClasses/header/AlreadySigendException.hpp"
#include "../../ExceptionClasses/header/ExecuteUnsignedException.hpp"
#include "../../ExceptionClasses/header/TooHighException.hpp"
#include "../../ExceptionClasses/header/TooLowException.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const std::string &target);
		virtual ~ShrubberyCreationForm( void );
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	private:
		virtual void executeConcrete() const;
};

#endif
