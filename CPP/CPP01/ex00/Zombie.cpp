/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:51:30 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:51:36 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie() {

}

Zombie::~Zombie() {
	std::cout << name << " is destroyed.\n";
}

std::string Zombie::getName() {
	return name;
}
void	Zombie::setName(std::string& value) {
	name = value;
}

void	Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
