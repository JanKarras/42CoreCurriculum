/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:03:20 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:03:21 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#ifndef DEBUG
#define DEBUG 1
#endif

#include <string>
#include <iostream>
class ClapTrap {
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);

	ClapTrap(std::string name);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void attack(const std::string& target);

protected:
	std::string	_name;
	size_t		_hitPoints;
	size_t		_energyPoints;
	size_t		_attackDamage;
};

#endif // CLAPTRAP_H
