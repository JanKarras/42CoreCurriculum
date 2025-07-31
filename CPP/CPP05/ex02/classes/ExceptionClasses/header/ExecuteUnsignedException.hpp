/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecuteUnsignedException.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:22:25 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:22:25 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTEUNSIGNEDEXCEPTION_HPP

#define EXECUTEUNSIGNEDEXCEPTION_HPP

#include "../../../include/libs.hpp"

class ExecuteUnsignedException : public std::exception {
	private:
		std::string messege;
	public:
		ExecuteUnsignedException( void );
		~ExecuteUnsignedException() throw();
		virtual const char *what() const throw();
};

#endif
