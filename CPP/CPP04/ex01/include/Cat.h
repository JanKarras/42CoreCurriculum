/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:09:02 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:09:10 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat  : public Animal {
public:
	Cat();
	~Cat();
	Cat(const Cat &other);
	Cat&operator=(const Cat &other);
	void setIdea(std::string idea, int i);
	std::string getIdea(int i);
	void makeSound( void ) const;
private:
	Brain *_brain;
};

#endif // CAT_H
