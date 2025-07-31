/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlreadySigendException.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:21:32 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:21:32 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALREADYSIGENDEXCEPTION_HPP

#define ALREADYSIGENDEXCEPTION_HPP

#include "../../../include/includes.hpp"

class AlreadySigendException : public std::exception {
	private:
		std::string messege;
	public:
		AlreadySigendException( void );
		~AlreadySigendException() throw();
		virtual const char *what() const throw();
};

#endif
