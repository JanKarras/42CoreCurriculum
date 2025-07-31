/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:28:19 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:28:21 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

int main()
{
	std::cout << "\nwith MutantStack \n\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "\nwith list \n\n";
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	std::list<int>::iterator itl = mlist.begin();
	std::list<int>::iterator itel = mlist.end();
	++itl;
	--itl;
	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	std::list<int> sl(mlist);
	return 0;
}
