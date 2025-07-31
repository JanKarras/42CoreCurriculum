/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:56:01 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:56:01 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP

#define LOGGER_HPP

#include "../../include/webserv.hpp"

class Logger {
	public:
		static void info(const char* message, ...);
		static void debug(const char* message, ...);
		static void error(const char* message, ...);
		static void warn(const char* message, ...);
};

#endif
