/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getTime.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:56:46 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:56:46 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

long long getCurrentTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long long microseconds = static_cast<long long>(tv.tv_sec) * 1000000 + tv.tv_usec;
	return microseconds;
}
