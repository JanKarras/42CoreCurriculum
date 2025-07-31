/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:25:54 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:25:54 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP

#include "../../../include/libs.hpp"
#include "../../DataClasses/header/Data.hpp"

class Data;

class Serializer {
	private:
		Serializer( void );
	public:
		virtual ~Serializer( void );
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
