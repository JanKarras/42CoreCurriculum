/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TooHighException.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:23:48 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:23:48 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/TooHighException.hpp"

TooHighException::TooHighException( void ) : message("Grade is to high!") {
	if(DEBUG) {
		std::cout << "TooHighException default constructor called\n";
	}
}

TooHighException::~TooHighException( void ) throw() {
	if(DEBUG) {
		std::cout << "TooHighException default deconstructor called\n";
	}
}

const char *TooHighException::what() const throw() {
	return (message.c_str());
}

