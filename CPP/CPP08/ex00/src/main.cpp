/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:27:49 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:27:49 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

int main( void ) {
	std::vector<int> v;

	for (size_t i = 0; i < 6; i++) {
		v.push_back(i);
	}

	std::list<int> l;

	for (size_t i = 0; i < 6; i++) {
		l.push_back(i);
	}

	try {
		easyfind(v, 3);
		easyfind(v, 10);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		easyfind(l, 3);
		easyfind(l, 10);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::vector<int> v_empty;

	try {
		easyfind(v_empty, 3);
		easyfind(v_empty, 10);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return (0);
}
