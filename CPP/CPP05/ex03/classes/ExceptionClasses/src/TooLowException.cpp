/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TooLowException.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:23:50 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:23:50 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/TooLowException.hpp"

TooLowException::TooLowException( void ) : message("Grade is to low!") {
	if(DEBUG) {
		std::cout << "TooLowException default constructor called\n";
	}
}

TooLowException::~TooLowException( void ) throw() {
	if(DEBUG) {
		std::cout << "TooLowException default deconstructor called\n";
	}
}

const char *TooLowException::what() const throw() {
	return (message.c_str());
}
