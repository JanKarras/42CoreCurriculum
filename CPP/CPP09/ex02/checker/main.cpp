/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:29:10 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:29:21 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <sstream>

bool is_sorted(const std::vector<int>& arr) {
	for (size_t i = 1; i < arr.size(); ++i) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	std::string line;
	std::vector<int> numbers;

	while (std::getline(std::cin, line)) {
		std::istringstream stream(line);
		int num;
		while (stream >> num) {
			numbers.push_back(num);
		}
	}

	if (is_sorted(numbers)) {
		std::cout << "Die Zahlen sind korrekt sortiert!" << std::endl;
	} else {
		std::cout << "Die Zahlen sind NICHT korrekt sortiert!" << std::endl;
	}

	return 0;
}
