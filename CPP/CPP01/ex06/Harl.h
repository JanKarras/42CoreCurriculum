/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:55:52 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:55:57 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

class Harl {
public:
	Harl(std::string level);
	~Harl();
	void	complain(std::string level);
	int		getLevel( void );
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	int		_level;
};

#endif // HARL_H
