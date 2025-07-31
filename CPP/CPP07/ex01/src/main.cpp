/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:26:59 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:26:59 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"



int main( void ) {
	int intArray[] = {1, 2, 3, 4, 5, 6};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Array before incrementing: ";
	iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intLength, incrementElement<int>);

	std::cout << "Array after incrementing: ";
	iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intLength, incrementElement<int>);

	char charArray[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	size_t intCharLength = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Array before incrementing: ";
	iter(charArray, intCharLength, printElement<char>);
	std::cout << std::endl;

	iter(charArray, intCharLength, incrementElement<char>);

	std::cout << "Array after incrementing: ";
	iter(charArray, intCharLength, printElement<char>);
	std::cout << std::endl;

	iter(charArray, intCharLength, incrementElement<char>);
	return (0);
}
