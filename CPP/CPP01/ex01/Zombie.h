/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:52:23 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:52:29 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
public:
	Zombie();
	~Zombie();

	void	announce(void);

	std::string getName();
	void setName(std::string& value);
private:
	std::string	name;
};

Zombie* zombieHorde( int N, std::string name );

#endif // ZOMBIE_H
