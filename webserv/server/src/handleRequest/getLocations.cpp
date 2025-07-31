/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getLocations.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:56:30 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:56:30 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

bool matchPathInDirTree(const dir &currentDir, const std::string &reqPath) {
	for (size_t i = 0; i < currentDir.files.size(); ++i) {
		if (currentDir.files[i].path == reqPath) {
			return true;
		}
	}

	if (currentDir.path == reqPath) {
		return true;
	}

	for (size_t j = 0; j < currentDir.dirs.size(); ++j) {
		if (matchPathInDirTree(currentDir.dirs[j], reqPath)) {
			return true;
		}
	}
	return false;
}

location* matchLocation(server &Server, const std::string &path, HttpRequest &req) {
	location *prefixMatch = NULL;
	size_t longestPrefix = 0;

	for (size_t i = 0; i < Server.locations.size(); i++) {
		location &loc = Server.locations[i];
		if (loc.regularLocation) {
			if (path.size() >= loc.ext.size() &&
				path.compare(path.size() - loc.ext.size(), loc.ext.size(), loc.ext) == 0) {

				bool methodAllowed =
					(req.method == GET && loc.get) ||
					(req.method == POST && loc.post) ||
					(req.method == DELETE && loc.del);

				if (methodAllowed) {
					return &loc;
				} else {
				}
			}
		}
	}

	for (size_t i = 0; i < Server.locations.size(); i++) {
		location &loc = Server.locations[i];
		if (!loc.regularLocation && path.find(loc.name) == 0) {
			if (loc.name.length() > longestPrefix) {
				prefixMatch = &loc;
				longestPrefix = loc.name.length();
			}
		}
	}

	if (prefixMatch) {
		return prefixMatch;
	}

	for (size_t i = 0; i < Server.locations.size(); i++) {
		location &loc = Server.locations[i];
		if (matchPathInDirTree(loc.tree, path)) {
			return &loc;
		}
	}

	return NULL;
}
