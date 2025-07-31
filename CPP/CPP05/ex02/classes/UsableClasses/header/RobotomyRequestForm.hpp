#ifndef RobotomyRequestForm_HPP

#define RobotomyRequestForm_HPP

#include "../../../include/libs.hpp"
#include "../../AbstractClasses/header/AForm.hpp"
#include "../../ExceptionClasses/header/AlreadySigendException.hpp"
#include "../../ExceptionClasses/header/ExecuteUnsignedException.hpp"
#include "../../ExceptionClasses/header/TooHighException.hpp"
#include "../../ExceptionClasses/header/TooLowException.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string &target);
		virtual ~RobotomyRequestForm( void );
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	private:
		virtual void executeConcrete() const;
};

#endif
