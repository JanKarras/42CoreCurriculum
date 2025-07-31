/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:24:27 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:24:27 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../classes/UsableClasses/header/Bureaucrat.hpp"
#include "../classes/UsableClasses/header/ShrubberyCreationForm.hpp"
#include "../classes/UsableClasses/header/RobotomyRequestForm.hpp"
#include "../classes/UsableClasses/header/PresidentialPardonForm.hpp"
#include "../classes/UsableClasses/header/Intern.hpp"

int	main() {
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		if (rrf) {
			std::cout << "The form the intern created\n" << *rrf;
		}
		delete rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			std::cout << "The form the intern created\n" << *rrf;
		}
		delete rrf;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

}
