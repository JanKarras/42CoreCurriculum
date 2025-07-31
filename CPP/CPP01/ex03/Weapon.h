/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:54:14 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:54:19 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {
public:
	Weapon();
	Weapon(std::string WeaponType);
	~Weapon();

	const std::string &getType() const;
	void setType(const std::string& value);

private:
	std::string type;
};

#endif
