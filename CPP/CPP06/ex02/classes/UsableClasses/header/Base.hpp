/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:26:17 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:26:17 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP

#define BASE_HPP

#include "../../../include/libs.hpp"

class Base {
	public:
		virtual ~Base( void );
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};
#endif
