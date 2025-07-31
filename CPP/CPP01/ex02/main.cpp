/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:52:43 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:52:43 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "This is the adress of the string " << &string << std::endl;
	std::cout << "This is the adress of the pointer " << stringPTR << std::endl;
	std::cout << "This is the adress of the reference " << &stringREF << std::endl;
	std::cout << "This is the value of the string " << string << std::endl;
	std::cout << "This is the value of the pointer " << *stringPTR << std::endl;
	std::cout << "This is the value of the reference " << stringREF << std::endl;
	return (0);
}
