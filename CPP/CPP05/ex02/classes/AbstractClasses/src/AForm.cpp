#include "../header/AForm.hpp"

AForm::AForm(const std::string &name, const std::string &target, int signGrade, int executeGrade)
	: _name(name), _target(target), _signGrade(signGrade), _executeGrade(executeGrade), _status(0) {
	if (DEBUG) {
		std::cout << "AForm default constructor called\n";
	}
	if (signGrade < 1 || executeGrade < 1) {
		throw TooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		throw TooLowException();
	}
}

AForm::~AForm( void ) {
	if (DEBUG) {
		std::cout << "AForm default deconstructor called\n";
	}
}

AForm::AForm(const AForm &other) : _name(other.getName()), _target(other.getTarget()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade()), _status(other.getStatus()) {

}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		_status = other.getStatus();
	}
	return (*this);
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (this->getStatus() == true) {
		throw AlreadySigendException();
	} else if (bureaucrat.getGrade() > _signGrade) {
		throw TooLowException();
	} else {
		_status = true;
	}
}

const std::string &AForm::getName( void ) const {
	return (_name);
}

const std::string &AForm::getTarget( void ) const {
	return (_target);
}

bool AForm::getStatus( void ) const {
	return (_status);
}

int AForm::getSignGrade( void ) const {
	return (_signGrade);
}

int AForm::getExecuteGrade( void ) const {
	return (_executeGrade);
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
	os	<< "AForm Name: " << AForm.getName() << std::endl
		<< "AForm Status: " << AForm.getStatus() << std::endl
		<< "From Signgrade: " << AForm.getSignGrade() << std::endl
		<< "From Executegrade: " << AForm.getExecuteGrade() << std::endl;
	return os;
}

AForm::AForm() : _signGrade(0), _executeGrade(0) {

}

void AForm::execute(Bureaucrat const & executor) const {
	if (!_status) {
		throw ExecuteUnsignedException();
	} else if (executor.getGrade() > _executeGrade) {
		throw TooLowException();
	} else {
		executeConcrete();
	}
}
