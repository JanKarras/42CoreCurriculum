/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:29:29 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:29:29 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

#define PMERGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <sys/time.h>
#include <ctime>
#include <cstdlib>



#ifndef DEBUG

#define DEBUG 0

#endif

struct CopyAndRemoveEverySecond {
	std::vector<int> &vec;
	bool toggle;

	CopyAndRemoveEverySecond(std::vector<int> &newVec) : vec(newVec), toggle(false){}

	bool operator()(int value) {
		toggle = !toggle;
		if (!toggle) {
			vec.push_back(value);
			return (true);
		}
		return (false);
	}
};

int stdtoint(std::string str);
long long getCurrentTime();
void printVec(std::vector<int> &vec);
void printDeq(const std::deque<int>& deq);
std::vector<int> merge_insertion_sort(std::vector<int> &A);
std::deque<int> merge_insertion_sort(std::deque<int>& arr);

#endif
