/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:54:56 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:55:06 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl() {
	// Constructor
}

Harl::~Harl() {
	// Destructor
}

void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << "I really do!\n";
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put";
	std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for";
	std::cout << "years whereas you started working here since last month.\n";
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level) {
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*infoAction)() = &Harl::info;
	void (Harl::*debugAction)() = &Harl::debug;
	void (Harl::*warningAction)() = &Harl::warning;
	void (Harl::*errorAction)() = &Harl::error;
	void (Harl::*actions[])() = {debugAction, infoAction, warningAction, errorAction};
	for (int i = 0; i < 4; i++){
		if (level == levels[i]) {
			(this->*actions[i])();
			return ;
		}
	}
	std::cout << "unknown level\n";
}
