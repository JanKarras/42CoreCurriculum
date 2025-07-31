/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:53:12 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:53:19 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
public:
	HumanA(std::string name, Weapon &_weapon);
	~HumanA();
	void	attack();
private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif // HUMANA_H
