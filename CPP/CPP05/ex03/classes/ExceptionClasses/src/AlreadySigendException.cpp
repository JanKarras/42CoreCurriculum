/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlreadySigendException.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:23:43 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:23:43 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AlreadySigendException.hpp"

AlreadySigendException::AlreadySigendException( void ) : messege("Form is already sigend") {

}

AlreadySigendException::~AlreadySigendException( void ) throw() {

}

const char *AlreadySigendException::what() const throw() {
	return (messege.c_str());
}
