/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:53:23 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:53:25 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(std::string name) :_name(name), _weapon(NULL){
	return ;
}

HumanB::~HumanB() {
	return ;
}

void HumanB::attack() {
	if (this->_weapon == NULL)
		std::cout << this->_name << " attacks with thier fists\n";
	else
		std::cout << this->_name << " attacks with thier " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
