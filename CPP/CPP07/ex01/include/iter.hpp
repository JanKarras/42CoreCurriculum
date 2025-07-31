/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:26:57 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:26:57 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEM_HPP

#define TEM_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *a, size_t length, void (*func)(T&)) {
	for (size_t i = 0; i < length; i++) {
		func(a[i]);
	}
}

template <typename T>
void printElement(T &element) {
	std::cout << element << " ";
}

template <typename T>
void incrementElement(T &element) {
	++element;
}

#endif
