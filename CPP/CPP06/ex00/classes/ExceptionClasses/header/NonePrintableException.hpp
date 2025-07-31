/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NonePrintableException.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:25:31 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:25:31 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NONEPRINTABLEEXCEPTION_HPP

#define NONEPRINTABLEEXCEPTION_HPP

#include "../../../include/libs.hpp"

class NonePrintableException : public std::exception {
	public :
		NonePrintableException( void );
		~NonePrintableException( void) throw();
		virtual const char *what() const throw();
	private:
		std::string _msg;
};

#endif
