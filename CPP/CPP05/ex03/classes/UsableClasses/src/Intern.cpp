/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:24:15 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:24:15 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

Intern::Intern( void ) {

}

Intern::~Intern( void) {

}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	if (this != &other) {

	}
	return (*this);
}

AForm *makePresident(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm *makeRobotomy(const std::string target) {
	return (new RobotomyRequestForm(target));
}


AForm *makeShrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}


AForm *Intern::makeForm(std::string name, std::string target) {
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobotomy, &makeShrubbery};
	std::string FormNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	for (int i = 0; i < 3; i++)
	{
		if (FormNames[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "Intern does not now this name. You should train him better or ask for Coffe\n";
	return (NULL);
}
