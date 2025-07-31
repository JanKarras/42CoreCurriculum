/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:21:58 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:21:58 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade)
	: _name(name), _status(0), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (DEBUG) {
		std::cout << "Form default constructor called\n";
	}
	if (signGrade < 1 || executeGrade < 1) {
		throw TooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		throw TooLowException();
	}
}

Form::~Form( void ) {
	if (DEBUG) {
		std::cout << "Form default deconstructor called\n";
	}
}

Form::Form(const Form &other) : _name(other.getName()), _status(other.getStatus()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade()) {

}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		_status = other.getStatus();
	}
	return (*this);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (this->getStatus() == true) {
		throw AlreadySigendException();
	} else if (bureaucrat.getGrade() > _signGrade) {
		throw TooLowException();
	} else {
		_status = true;
	}
}

std::string Form::getName( void ) const {
	return (_name);
}

bool Form::getStatus( void ) const {
	return (_status);
}

int Form::getSignGrade( void ) const {
	return (_signGrade);
}

int Form::getExecuteGrade( void ) const {
	return (_executeGrade);
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os	<< "Form Name: " << form.getName() << std::endl
		<< "Form Status: " << form.getStatus() << std::endl
		<< "From Signgrade: " << form.getSignGrade() << std::endl
		<< "From Executegrade: " << form.getExecuteGrade() << std::endl;
	return os;
}
