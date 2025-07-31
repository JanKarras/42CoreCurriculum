/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:51:57 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:51:57 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void) {
	int N;

	N = 5;
	Zombie *horde = zombieHorde(N, "KEK");
	if (horde) {
		for (int i = 0; i < N; i++)
			horde[i].announce();
		delete[] horde;
	}
	else
		std::cout << "Horde creaion faild\n";
	horde = zombieHorde(N, "LOL");
	if (horde) {
		for (int i = 0; i < N; i++)
			horde[i].announce();
		delete[] horde;
	}
	else
		std::cout << "Horde creaion faild\n";
	return (0);
}
