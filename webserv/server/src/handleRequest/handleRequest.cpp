/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleRequest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:56:34 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:56:34 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"


void handleRequest(int clientFd, ConfigData &configData) {
	std::map<int, ConfigData> data;
	data[configData.port] = configData;

	server &Server = getServer(clientFd, configData);

	HttpRequest req = getReq(Server, clientFd);

	if (req.method == INVALID) {
		return ;
	}

	HttpResponse &res = Server.serverContex.responses[clientFd];

	normelaizePaths(req, Server);

	location *foundLocation = matchLocation(Server, req.path, req);

	if (foundLocation) {
		bool error = false;
		if (foundLocation->client_max_body_size != 0) {
			if (req.content_length > foundLocation->client_max_body_size) {
				handle413(res);
				error = true;
			}
		} else if (Server.client_max_body_size != 0) {
			if (req.content_length > Server.client_max_body_size) {
				handle413(res);
				error = true;
			}
		}
		if (!error) {
			if (!foundLocation->redirect.empty()) {
				bool isValidLocationName = false;
				std::string red = foundLocation->redirect;
				for (size_t i = 0; i < Server.locations.size(); i++) {
					if (red == Server.locations[i].name) {
						req.path = foundLocation->redirect + req.path.substr(foundLocation->name.size());
						foundLocation = &Server.locations[i];
						isValidLocationName = true;
						break;
					}
				}
				if (isValidLocationName == false) {
					handle404(res);
					return;
				}
			}

			if (req.method == GET) {
				if (!foundLocation->get) {
					Logger::error("Method GET not allowed for location %s", foundLocation->name.c_str());
					handle405(res);
				} else {
					routeRequestGET(req, res, Server, *foundLocation, clientFd);
				}
			} else if (req.method == POST) {
				if (!foundLocation->post) {
					Logger::error("Method POST not allowed for location %s", foundLocation->name.c_str());
					handle405(res);
				} else {
					routeRequestPOST(req, res, Server, *foundLocation, clientFd);
				}
			} else if (req.method == DELETE) {
				if (!foundLocation->del) {
					Logger::error("Method DELETE not allowed for location %s", foundLocation->name.c_str());
					handle405(res);
				} else {
					routeRequestDELETE(req, res, Server, *foundLocation);
				}
			} else {
				Logger::error("Method not allowed: %i", req.method);
				handle405(res);
			}
		}
	} else {
		Logger::error("Unknown location or file for path: %s", req.path.c_str());
		handle404(res);
	}

	res.version = req.version;
	res.state = SENDING_HEADERS;

	if (req.method == HEAD) {
		res.body.clear();
	}

	addResponseEpoll(Server, clientFd, configData, res);

	res.startTime = getCurrentTime();
}

