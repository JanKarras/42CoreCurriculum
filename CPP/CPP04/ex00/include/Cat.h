/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:05:59 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:06:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat  : public Animal {
public:
	Cat();
	~Cat();
	Cat(const Cat &other);
	Cat&operator=(const Cat &other);
	void makeSound( void ) const;
private:

};

#endif // CAT_H
