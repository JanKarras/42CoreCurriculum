/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:25:39 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:25:39 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libs.hpp"
#include "../classes/AbstractClasses/header/ScalarConverter.hpp"


int main(void) {
	// ScalarConverter::convert("42.0f");
	// return (0);
	std::string testCases[] = {
	"a",
	"42",
	"42.42",
	"42.42f",
	"+inff",
	"+inf",
	"-inff",
	"-inf",
	"nan",
	"nanf",
	"0.0",
	"123456789012345678901234567890",
	"",
	"  ",
	"42.0a",
	"0",
	"nan",
	"42.0f",
	"end"
	};
	for (size_t i = 0; testCases[i] != "end"; i++) {
		std::cout << "\nTesting: \"" << testCases[i] << "\"\n";
		try {
			ScalarConverter::convert(testCases[i]);
		} catch (const std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return 0;
}
