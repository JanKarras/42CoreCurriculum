/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:29:00 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:29:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

bool checkInput(std::string str) {
	std::istringstream iss(str);
	std::string token;
	int operantCount = 0;

	while (iss >> token) {
		bool isNumber = true;
		for (size_t i = 0; i < token.length(); i++) {
			if (!isdigit(token[i]) && token[i] != '.') {
				isNumber = false;
				break;
			}
		}
		if (isNumber) {
			operantCount++;
		} else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (operantCount < 2) {
				return (false);
			}
			operantCount--;
		} else {
			return (false);
		}
	}
	return (operantCount == 1);
}


int main (int argc, char **argv) {
	if (argc != 2) {
		std::cout << "bad arg num\n";
		return (1);
	}

	std::string input = argv[1];
	if (input.empty()) {
		return (0);
	}

	if (!checkInput(input)) {
		std::cout << "Error\n";
		return (1);

	}

	std::istringstream iss(argv[1]);
	std::string token;
	std::stack<double> stack;

	while (iss >> token) {
		bool isNumber = true;
		for (size_t i = 0; i < token.length(); i++) {
			if (!isdigit(token[i]) && token[i] != '.') {
				isNumber = false;
				break;
			}
		}
		if (isNumber) {
			double value = atof(token.c_str());
			stack.push(value);
		} else {
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			double res = 0;
			if (token == "+") {
				res = a + b;
			} else if (token == "-") {
				res = a - b;
			} else if (token == "*") {
				res = a * b;
			} else if (token == "/") {
				if (b == 0.0) {
					std::cout << "Division by zero\n";
					return (1);
				}
				res = a / b;
			}
			stack.push(res);
		}
	}
	std::cout << stack.top() << std::endl;
	return (0);
}
