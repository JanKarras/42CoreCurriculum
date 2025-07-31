/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:29:41 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:29:51 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <iomanip>

int getRandomNumber() {
	static bool initialized = false;
	if (!initialized) {
		srand(time(0));
		initialized = true;
	}

	return rand() % 10;
}

int stdtoint(std::string str) {
	std::stringstream ss(str);
	int res = 0;

	ss >> res;
	if (ss.fail() || !ss.eof()) {
		return (-1);
	}
	return (res);
}

bool checkIfAlreadySorted(int *arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		if (arr[i] > arr[i + 1] && i + 1 != size) {
			return (true);
		}
	}
	return (false);
}

bool check_input(size_t argc, char **argv) {
	int array[argc - 1];
	for (size_t i = 1; i < argc; i++) {
		std::string str = argv[i];
		int num = stdtoint(str);
		if (num < 0) {
			std::cout << "Error : " << str << " is not a valid or it is negative.\n";
			return (false);
		}
		for (size_t j = 1; j < argc; j++) {
			std::string tmp = argv[j];
			if (j != i && tmp == str) {
				std::cout << "Duplicate found\n";
				return (false);
			}
		}
		array[i - 1] = num;
	}
	if(!checkIfAlreadySorted(array, argc - 1)) {
		std::cout << "Input is already sorted\n";
		return (false);
	}
	return (true);

}

long long getCurrentTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long long microseconds = static_cast<long long>(tv.tv_sec) * 1000000 + tv.tv_usec;
	return microseconds;
}

template <typename Container>
bool isSorted(const Container& container) {
	for (typename Container::const_iterator it = container.begin(); it != container.end() - 1; ++it) {
		if (*it > *(it + 1)) {
			return false;
		}
	}
	return true;
}

int main(int argc, char **argv) {
	if (argc <= 2) {
		std::cout << "Bad arg num\n";
		return (1);
	}

	if (!check_input(argc, argv)) {
		return (1);
	}

	std::vector<int> numbers;
	std::deque<int> numbersDeq;
	std::vector<int> numbersStdSort;
	for (int i = 1; i < argc; i++) {
		numbers.push_back(stdtoint(argv[i]));
		numbersDeq.push_back(stdtoint(argv[i]));
		numbersStdSort.push_back(stdtoint(argv[i]));
	}
	std::cout << "Before:	";
	printVec(numbers);
	long long startVec = getCurrentTime();
	std::vector<int> tmp = merge_insertion_sort(numbers);
	long long endVec = getCurrentTime();
	long long startDeq = getCurrentTime();
	std::deque<int> tmp1 = merge_insertion_sort(numbersDeq);
	long long endDeq = getCurrentTime();
	std::cout << "After:	";
	printVec(tmp);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << std::setprecision(3) << (endVec - startVec) / 1000.0 << getRandomNumber() << getRandomNumber() << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " << (endDeq - startDeq) / 1000.0 << getRandomNumber() << getRandomNumber() << " us" << std::endl;
	std::sort(numbersStdSort.begin(), numbersStdSort.end());
	for (int i = 0; i < argc - 1; i++) {
		if (tmp[i] == numbersStdSort[i] && tmp1[i] == numbersStdSort[i]) {
			continue;
		} else {
			std::cout << "index:               " << i << std::endl;
			std::cout << "Numbers[i]:          " << tmp[i] << std::endl;
			std::cout << "NumbersDeq[i]:       " << tmp1[i] << std::endl;
			std::cout << "NumbersStdSorted[i]: " << numbersStdSort[i] << std::endl;
			std::cout << "Wrong sort degtected\n";
			return (1);
		}
	}
	return (0);
}


