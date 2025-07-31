/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:22:15 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:22:15 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP

#define AFORM_HPP

#include "../../../include/libs.hpp"
#include "../../UsableClasses/header/Bureaucrat.hpp"
#include "../../ExceptionClasses/header/AlreadySigendException.hpp"
#include "../../ExceptionClasses/header/ExecuteUnsignedException.hpp"
#include "../../ExceptionClasses/header/TooHighException.hpp"
#include "../../ExceptionClasses/header/TooLowException.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		std::string const _target;
		int const _signGrade;
		int const _executeGrade;
		bool _status;
		AForm( void );
		virtual void executeConcrete() const = 0;
	public:
		AForm(const std::string &name, const std::string &target, int signGrade, int executeGrade);
		AForm(const AForm &other);
		virtual ~AForm( void );
		AForm &operator=(const AForm &other);
		const std::string &getName( void ) const;
		const std::string &getTarget( void ) const;
		bool getStatus( void ) const;
		int getSignGrade( void ) const;
		int getExecuteGrade( void ) const;
		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
