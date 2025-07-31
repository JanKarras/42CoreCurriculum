/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:22:42 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:22:42 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP

#include "../../../include/libs.hpp"
#include "../../ExceptionClasses/header/AlreadySigendException.hpp"
#include "../../ExceptionClasses/header/ExecuteUnsignedException.hpp"
#include "../../ExceptionClasses/header/TooHighException.hpp"
#include "../../ExceptionClasses/header/TooLowException.hpp"
#include "../../AbstractClasses/header/AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat( void );
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		std::string const &getName( void ) const;
		int getGrade( void ) const;
		void increment( void );
		void decrement( void );
		void signAForm(AForm &AForm) const;
		void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
