/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:44:20 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/30 15:46:15 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main()
{
	Zombie	*zombie;

	zombie = newZombie("HS");
	zombie->announce();
	delete(zombie);
	randomChump("KEK");
	return (0);
}
