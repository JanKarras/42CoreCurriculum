/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:06:04 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:06:13 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog&operator=(const Dog &other);
	void makeSound( void ) const;

private:

};

#endif // DOG_H
