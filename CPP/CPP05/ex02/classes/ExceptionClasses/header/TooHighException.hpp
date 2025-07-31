/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TooHighException.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:22:27 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:22:27 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOHIGHEXPETION_HPP

#define TOOHIGHEXPETION_HPP

#include "../../../include/libs.hpp"

class TooHighException : public std::exception {
	private:
		std::string message;
	public:
		TooHighException( void );
		~TooHighException() throw();
		virtual const char *what() const throw();
};

#endif
