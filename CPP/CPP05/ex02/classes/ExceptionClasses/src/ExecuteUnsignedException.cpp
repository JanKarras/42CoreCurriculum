/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecuteUnsignedException.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:22:34 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:22:34 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ExecuteUnsignedException.hpp"

ExecuteUnsignedException::ExecuteUnsignedException( void ) : messege("Form ist unsigned") {

}

ExecuteUnsignedException::~ExecuteUnsignedException( void ) throw() {

}

const char *ExecuteUnsignedException::what() const throw() {
	return (messege.c_str());
}
