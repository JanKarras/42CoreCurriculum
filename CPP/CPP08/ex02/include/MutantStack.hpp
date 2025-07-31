/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:28:15 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:28:15 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP

#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack( void );
		~MutantStack( void );
		MutantStack(const MutantStack<T> &other);
		MutantStack<T> &operator=(const MutantStack<T> &other);

		typedef typename std::stack<T>::container_type under_ctr;
		typedef typename under_ctr::iterator iterator;
		typedef typename under_ctr::const_iterator const_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "../src/MutantStack.tpp"


#endif
