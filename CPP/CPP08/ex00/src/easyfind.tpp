/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:27:48 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:27:48 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void easyfind(T &container, int second) {
	typename T::iterator it = std::find(container.begin(), container.end(), second);

	if (it != container.end()) {
		std::cout << "Element found: " << *it << std::endl;
	} else {
		throw std::out_of_range("Element not found in container");
	}
}
