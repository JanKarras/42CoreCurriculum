/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epollHup.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:57:15 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:57:15 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/webserv.hpp"

void epollHup(ConfigData &configData, int i) {
	bool tmp = false;

	for (size_t j = 0; j < configData.servers.size(); ++j) {
	ServerContext &srv = configData.servers[j].serverContex;
		for (std::map<int, int>::iterator it = srv.fds.begin(); it != srv.fds.end(); ++it) {
			if (it->second == configData.events[i].data.fd) {
				int clientFd = it->first;
				HttpResponse &res = srv.responses[clientFd];
				epoll_ctl(configData.epollFd, EPOLL_CTL_DEL, configData.events[i].data.fd, NULL);
				close(configData.events[i].data.fd);
				srv.fds.erase(clientFd);
				srv.pids.erase(clientFd);
				res.readFromCgiFinished = true;
				res.state = SENDING_HEADERS;
				tmp = true;
				parseCgiContent(res);
				break;
			}
		}

		if (tmp) {
			break;
		}
	}
}
