/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:59:43 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/08 13:10:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int	main(int argc, char **argv) {
	if (argc != 2) {
		return (std::cout << "bad arg nb\n", 1);
	}
	Harl harl(argv[1]);
	if (harl.getLevel() == -1) {
		return (std::cout << "[ Probably complaining about insignificant problems ]\n", 0);
	}
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("TEST");
	return (0);
}
