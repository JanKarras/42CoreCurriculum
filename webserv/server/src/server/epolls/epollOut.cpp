/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epollOut.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:57:20 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:57:21 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/webserv.hpp"

void epollOut(ConfigData &configData, int i) {
	bool tmp = false;

	for (size_t j = 0; j < configData.servers.size(); j++) {
		ServerContext &srv = configData.servers[j].serverContex;
		for (std::map<int, int>::iterator it = srv.cgifds.begin(); it != srv.cgifds.end(); it++) {
			if (it->second == configData.events[i].data.fd) {
				handleCgiWrite(configData, i, srv);
				tmp = true;
				break;
			}
		}
		if (tmp) {
			break;
		}
	}

	if (tmp) {
		return;
	} else {
		handleEventRes(configData, i);
	}
}
