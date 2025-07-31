/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:11:40 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:11:47 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain {
public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain&operator=(const Brain &other);
	void setIdea(std::string idea, int i);
	std::string getIdea(int i);
private:
	std::string _ideas[100];
};

#endif // BRAIN_H
