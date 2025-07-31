/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:12:03 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:12:11 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog&operator=(const Dog &other);
	void setIdea(std::string idea, int i);
	std::string getIdea(int i);
	void makeSound( void ) const;

private:
	Brain *_brain;
};

#endif // DOG_H
