/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:24:19 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:24:19 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", target , 72, 45) {

}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {

	}
	return (*this);
}

void RobotomyRequestForm::executeConcrete() const {
	std::cout << "Drilling sounds\n" << this->getTarget();
	if (rand() % 2) {
		std::cout << " has been successfully robotimized!" << std::endl;
	} else {
		std::cout << " had some problems and its robotomy failed!" << std::endl;
	}
}
