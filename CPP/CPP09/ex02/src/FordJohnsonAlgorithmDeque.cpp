/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnsonAlgorithmDeque.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:29:33 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:29:33 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void printDeq(std::deque<int>& deq) {
	for (size_t i = 0; i < deq.size(); i++) {
		std::cout << deq[i] << " ";
	}
	std::cout << std::endl;
}

void printPairs(std::deque<std::deque<int> >& pairs) {
	std::cout<< "Print pairs\n";
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << "(" << pairs[i][0] << ", " << pairs[i][1] << ") ";
	}
	std::cout << std::endl;
}

int jacobsthalDeq(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jacobsthalDeq(n - 1) + 2 * jacobsthalDeq(n - 2);
}

std::deque<int> build_jacob_sequenceDeq(int size) {
	std::deque<int> sequence;
	int i = 3;
	while (jacobsthalDeq(i) < size - 1) {
		sequence.push_back(jacobsthalDeq(i));
		i++;
	}
	return sequence;
}

std::deque<std::deque<int> > create_pairs(std::deque<int>& arr) {
	std::deque<std::deque<int> > pairs;
	std::deque<int> temp;

	for (size_t i = 0; i < arr.size(); i++) {
		temp.push_back(arr[i]);
		if (temp.size() == 2) {
			pairs.push_back(temp);
			temp.clear();
		}
	}
	if (!temp.empty()) {
		pairs.push_back(temp);
	}
	return pairs;
}

void sort_pairs(std::deque<std::deque<int> >& pairs) {
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i].size() == 2 && pairs[i][0] > pairs[i][1]) {
			std::swap(pairs[i][0], pairs[i][1]);
		}
	}
}

void insertion_sort_pairs(std::deque<std::deque<int> >& pairs, int n) {
	if (n < 1) return;
	insertion_sort_pairs(pairs, n - 1);
	std::deque<int> temp = pairs[n];
	int j = n - 1;
	while (j >= 0 && pairs[j][1] > temp[1]) {
		pairs[j + 1] = pairs[j];
		j--;
	}
	pairs[j + 1] = temp;
}

std::deque<int> merge_sorted_pairs(std::deque<std::deque<int> >& sorted_pairs, int extra) {
	std::deque<int> S, pend;

	for (size_t i = 0; i < sorted_pairs.size(); i++) {
		S.push_back(sorted_pairs[i][1]);
		pend.push_back(sorted_pairs[i][0]);
	}

	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());

	std::deque<int> jacob_seq = build_jacob_sequenceDeq(pend.size() - 1);

	while (!pend.empty()) {
		int idx = (jacob_seq.empty()) ? 0 : jacob_seq.front() - 1;
		if (!jacob_seq.empty()) jacob_seq.erase(jacob_seq.begin());

		int val = pend[idx];

		std::deque<int>::iterator it = std::lower_bound(S.begin(), S.end(), val);
		S.insert(it, val);

		pend.erase(pend.begin() + idx);
	}
	if (extra != -1) {
		std::deque<int>::iterator it = std::lower_bound(S.begin(), S.end(), extra);
		S.insert(it, extra);
	}

	return S;
}

std::deque<int> merge_insertion_sort(std::deque<int>& arr) {

	int extra = -1;
	if (arr.size() % 2 != 0) {
		extra = arr.back();
		arr.pop_back();
	}

	std::deque<std::deque<int> > pairs = create_pairs(arr);
	sort_pairs(pairs);
	insertion_sort_pairs(pairs, pairs.size() - 1);
	std::deque<int> sorted_array = merge_sorted_pairs(pairs, extra);

	return sorted_array;
}
