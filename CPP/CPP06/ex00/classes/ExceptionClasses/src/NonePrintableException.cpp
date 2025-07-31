/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NonePrintableException.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:25:34 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:25:34 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/NonePrintableException.hpp"

NonePrintableException::NonePrintableException( void ) : _msg("non displayable characters detected\n") {
	if (DEBUG) {
		std::cout << "NonePrintableException default constructor called\n";
	}
}

NonePrintableException::~NonePrintableException( void ) throw() {
	if (DEBUG) {
		std::cout << "NonePrintableException default destructor called\n";
	}
}

const char *NonePrintableException::what( void ) const throw() {
	return (_msg.c_str());
}
