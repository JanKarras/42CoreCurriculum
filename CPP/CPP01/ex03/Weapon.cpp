/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:54:01 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:54:09 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon() {
	return ;
}

Weapon::Weapon(std::string WeaponType) : type(WeaponType) {
	return ;
}

Weapon::~Weapon() {
	return ;
}

const std::string &Weapon::getType() const{
	return this->type;
}
void Weapon::setType(const std::string& value) {
	type = value;
}
