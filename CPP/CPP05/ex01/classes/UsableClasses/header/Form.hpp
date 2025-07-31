/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:21:53 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:21:53 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

#define FORM_HPP

#include "../../../include/includes.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _status;
		int const _signGrade;
		int const _executeGrade;
	public:
		Form(std::string name, int signGrade, int executeGrade);
		~Form( void );
		Form(const Form &other);
		Form &operator=(const Form &other);
		void beSigned(Bureaucrat &bureaucrat);
		std::string getName( void ) const;
		bool getStatus( void ) const;
		int getSignGrade( void ) const;
		int getExecuteGrade( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif
