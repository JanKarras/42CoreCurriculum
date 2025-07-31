/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:12:14 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:12:23 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const std::string type);
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal&operator=(const WrongAnimal &other);
	std::string getType( void ) const;
	void makeSound( void ) const;
protected:
	std::string _type;

};


#endif // WRONGANIMAL_H
