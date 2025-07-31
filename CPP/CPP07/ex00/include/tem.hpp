/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tem.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:26:52 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:26:52 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEM_HPP

#define TEM_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b) {
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b) {
	if (a == b) {
		return (b);
	} else if (a < b) {
		return (a);
	} else {
		return (b);
	}
}

template <typename T>
T max(T a, T b) {
	if (a == b) {
		return (b);
	} else if (a > b) {
		return (a);
	} else {
		return (b);
	}
}
#endif
