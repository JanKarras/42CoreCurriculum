#ifndef SPAN_HPP

#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <limits>
#include <set>

class Span {
	public:
		Span(unsigned int N);
		~Span( void );
		Span(const Span &other);
		Span &operator=(const Span &other);
		void addNumber(int nb);
		int longesSpan( void ) const;
		int shortestSpan( void ) const;
		unsigned int getSize( void ) const;
		const std::vector<int> &getNumbers( void ) const;
		void addRange(const std::vector<int>::iterator begin, const std::vector<int>::iterator end);
	private:
		unsigned int _n;
		std::vector<int> _vec;
};

std::ostream &operator<<(std::ostream &out, const Span &other);

#endif
