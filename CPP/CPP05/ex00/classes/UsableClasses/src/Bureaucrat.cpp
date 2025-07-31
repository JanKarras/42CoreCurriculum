#include "../header/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (DEBUG) {
		std::cout << "Bureaucrat, with name " << name << " and with grade " << grade << ", constructor called\n";
	}
	if (grade < 1) {
		throw TooHighException();
	} else if (grade > 150) {
		throw TooLowException();
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
		throw TooHighException();
	} else {
		_grade--;
	}
}

void Bureaucrat::decrement( void) {
	if (_grade + 1 > 150) {
		throw TooLowException();
	} else {
		_grade++;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return os;
}
