/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:53:02 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:53:05 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)  {
	return ;
}

HumanA::~HumanA() {
	return ;
}

void HumanA::attack() {
	std::cout << this->_name << " attacks with thier " << this->_weapon.getType() << std::endl;
}
