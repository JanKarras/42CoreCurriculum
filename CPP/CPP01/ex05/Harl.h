/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:55:11 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:55:17 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

class Harl {
public:
	Harl();
	~Harl();
	void	complain(std::string level);

private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

#endif // HARL_H
