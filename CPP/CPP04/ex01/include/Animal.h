/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:08:46 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:08:48 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
public:
	Animal();
	Animal(const std::string type);
	virtual ~Animal();
	Animal(const Animal &other);
	Animal&operator=(const Animal &other);
	std::string getType( void ) const;
	virtual void makeSound( void ) const;
protected:
	std::string _type;

};


#endif // ANIMAL_H
