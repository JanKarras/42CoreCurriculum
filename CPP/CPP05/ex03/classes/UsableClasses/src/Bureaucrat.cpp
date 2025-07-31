/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:24:12 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:24:12 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (DEBUG) {
		std::cout << "Bureaucrat, with name " << name << " and with grade " << grade << ", constructor called\n";
	}
	if (grade < 1) {
		throw TooLowException();
	} else if (grade > 150) {
		throw TooHighException();
	} else {
		_grade = grade;
	}
}

Bureaucrat::~Bureaucrat( void ) {
	if (DEBUG) {
		std::cout << "Bureaucrat, with name " << _name << " and with grade " << _grade << ", standart deconstructor called\n";
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade()) {
	if (DEBUG) {
		std::cout << "Bureaucrat, with name " << _name << " and with grade " << _grade << ", copy constructor called\n";
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (DEBUG) {
		std::cout << "Bureaucrat, with name " << _name << " and with grade " << _grade << ", copy assigment constructor called\n";
	}
	if (this != & other) {
		_grade = other.getGrade();
	}
	return (*this);
}

std::string const &Bureaucrat::getName( void ) const {
	return (_name);
}

int Bureaucrat::getGrade( void ) const {
	return (_grade);
}

void Bureaucrat::increment( void ) {
	if (_grade - 1 < 1) {
		throw TooLowException();
	} else {
		_grade--;
	}
}

void Bureaucrat::decrement( void) {
	if (_grade + 1 > 150) {
		throw TooHighException();
	} else {
		_grade++;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return os;
}

void Bureaucrat::signAForm(AForm &AForm) const {
	try {
		AForm.beSigned(*this);
		std::cout << _name << " signed " << AForm.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " cannot sign " << AForm.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executet " << form;
	} catch (std::exception& e) {
		std::cout << _name << " could not execute the form " << form.getName() << ", because " << e.what() << std::endl;
	}
}
