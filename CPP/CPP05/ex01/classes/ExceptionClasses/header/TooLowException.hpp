/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TooLowException.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:21:38 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:21:38 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLOWException_HPP

#define TOOLOWException_HPP

#include "../../../include/includes.hpp"

class TooLowException : public std::exception {
	private:
		std::string message;
	public:
		TooLowException( void );
		~TooLowException() throw();
		virtual const char *what() const throw();
};

#endif
