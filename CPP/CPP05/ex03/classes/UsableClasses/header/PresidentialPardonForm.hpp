/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:24:04 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:24:04 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP

#define PresidentialPardonForm_HPP

#include "../../../include/libs.hpp"
#include "../../AbstractClasses/header/AForm.hpp"
#include "../../ExceptionClasses/header/AlreadySigendException.hpp"
#include "../../ExceptionClasses/header/ExecuteUnsignedException.hpp"
#include "../../ExceptionClasses/header/TooHighException.hpp"
#include "../../ExceptionClasses/header/TooLowException.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(const std::string &target);
		virtual ~PresidentialPardonForm( void );
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	private:
		virtual void executeConcrete() const;
};

#endif
