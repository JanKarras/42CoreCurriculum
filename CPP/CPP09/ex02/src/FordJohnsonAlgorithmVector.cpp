#include "../include/PmergeMe.hpp"

void printVec(std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void printPairs(std::vector<std::vector<int> >& pairs) {
	std::cout<< "Print pairs\n";
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << "(" << pairs[i][0] << ", " << pairs[i][1] << ") ";
	}
	std::cout << std::endl;
}

int jacobsthal(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> build_jacob_sequence(int size) {
	std::vector<int> sequence;
	int i = 3;
	while (jacobsthal(i) < size - 1) {
		sequence.push_back(jacobsthal(i));
		i++;
	}
	return sequence;
}

std::vector<std::vector<int> > create_pairs(std::vector<int>& arr) {
	std::vector<std::vector<int> > pairs;
	std::vector<int> temp;

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

void sort_pairs(std::vector<std::vector<int> >& pairs) {
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i].size() == 2 && pairs[i][0] > pairs[i][1]) {
			std::swap(pairs[i][0], pairs[i][1]);
		}
	}
}

void insertion_sort_pairs(std::vector<std::vector<int> >& pairs, int n) {
	if (n < 1) return;
	insertion_sort_pairs(pairs, n - 1);
	std::vector<int> temp = pairs[n];
	int j = n - 1;
	while (j >= 0 && pairs[j][1] > temp[1]) {
		pairs[j + 1] = pairs[j];
		j--;
	}
	pairs[j + 1] = temp;
}

std::vector<int> merge_sorted_pairs(std::vector<std::vector<int> >& sorted_pairs, int extra) {
	std::vector<int> S, pend;

	for (size_t i = 0; i < sorted_pairs.size(); i++) {
		S.push_back(sorted_pairs[i][1]);
		pend.push_back(sorted_pairs[i][0]);
	}

	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());
	std::vector<int> jacob_seq = build_jacob_sequence(pend.size() - 1);

	while (!pend.empty()) {
		int idx = (jacob_seq.empty()) ? 0 : jacob_seq.front() - 1;
		if (!jacob_seq.empty()) jacob_seq.erase(jacob_seq.begin());

		int val = pend[idx];

		std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), val);
		S.insert(it, val);

		pend.erase(pend.begin() + idx);
	}
	if (extra != -1) {
		std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), extra);
		S.insert(it, extra);
	}

	return S;
}

std::vector<int> merge_insertion_sort(std::vector<int>& arr) {

	int extra = -1;
	if (arr.size() % 2 != 0) {
		extra = arr.back();
		arr.pop_back();
	}

	std::vector<std::vector<int> > pairs = create_pairs(arr);
	sort_pairs(pairs);
	insertion_sort_pairs(pairs, pairs.size() - 1);
	std::vector<int> sorted_array = merge_sorted_pairs(pairs, extra);

	return sorted_array;
}
