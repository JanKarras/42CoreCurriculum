/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:28:06 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:28:06 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span(unsigned int N) : _n(N) {

}

Span::~Span( void ) {

}

Span::Span(const Span &other) : _n(other._n), _vec(other._vec){

}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_n = other._n;
		for (std::vector<int>::const_iterator it = other._vec.begin(); it != other._vec.end(); ++it) {
			this->_vec.push_back(*it);
		}
	}
	return (*this);
}

void Span::addNumber(int nb) {
	if (this->_vec.size() < this->_n) {
		this->_vec.push_back(nb);
	} else {
		throw std::out_of_range("Max numbers stored. Container is full");
	}
}

int Span::longesSpan( void ) const {
	if (_vec.size() <= 1) {
		throw std::exception();
	} else {
		int minVal = *std::min_element(_vec.begin(), _vec.end());
		int maxVal = *std::max_element(_vec.begin(), _vec.end());

		return (maxVal - minVal);
	}
}

int Span::shortestSpan( void ) const {
	if (_vec.size() <= 1) {
		throw std::exception();
	} else {
		std::vector<int> sortedVec = _vec;

		std::sort(sortedVec.begin(), sortedVec.end());
		int minSpan = std::numeric_limits<int>::max();
		for (size_t i = 1; i < sortedVec.size(); i++){
			int span = sortedVec[i] - sortedVec[i - 1];
			if (span < minSpan) {
				minSpan = span;
			}
		}
		return (minSpan);
	}
}

void Span::addRange(const std::vector<int>::iterator begin, const std::vector<int>::iterator end) {
	if (_vec.size() + std::distance(begin, end) > _n) {
		throw std::out_of_range("Range to big!");
	} else {
		_vec.insert(_vec.end(), begin, end);
	}
}

unsigned int Span::getSize( void ) const {
	return (_vec.size());
}

const std::vector<int> & Span::getNumbers( void ) const {
	return (_vec);
}

std::ostream &operator<<(std::ostream &out, const Span &other) {
	out << "Span (max size: " << other.getSize() << "):[";
	const std::vector<int>& numbers = other.getNumbers();
	for (size_t i = 0; i < numbers.size(); ++i) {
		out << numbers[i];
		if (i != numbers.size() - 1) {
			out << ", ";
		}
	}
	out << "]";
	return out;
}
