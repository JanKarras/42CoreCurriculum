/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:20:59 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:20:59 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP

#include "../../../include/includes.hpp"

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
