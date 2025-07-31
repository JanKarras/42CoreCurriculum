/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:26:01 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:26:01 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP

#define DATA_HPP

#include "../../../include/libs.hpp"

class Data {
	public:
		Data(int n, std::string text);
		int _num;
		std::string _text;
};

#endif
