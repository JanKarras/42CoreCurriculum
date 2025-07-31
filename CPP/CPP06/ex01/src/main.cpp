/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:26:08 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:26:08 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libs.hpp"
#include "../classes/AbstractClasses/header/Serializer.hpp"
#include "../classes/DataClasses/header/Data.hpp"

int main(void) {
	Data *original = new Data(42, "Hello World");

	uintptr_t raw = Serializer::serialize(original);

	Data *deserialized = Serializer::deserialize(raw);

	if (original == deserialized) {
		std::cout << "Test passed: The deserialized pointer is equal to the original pointer." << std::endl;
		std::cout << "Original Data: " << original->_num << " - " << original->_text << std::endl;
		std::cout << "Deserialized Data: " << deserialized->_num << " - " << deserialized->_text << std::endl;
	} else {
		std::cout << "Test failed: The deserialized pointer is not equal to the original pointer." << std::endl;
	}
	delete original;
	return (0);
}
