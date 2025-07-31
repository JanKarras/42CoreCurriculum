/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:56:27 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:56:27 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

bool checkPath(std::string path) {
	if (access(path.c_str(), F_OK) != 0) {
		Logger::error("File does not exists\n");
		return (false);
	}

	if (access(path.c_str(), R_OK) != 0) {
		Logger::error("File is not readable\n");
		return (false);
	}

	return (true);
}

std::string readFile(std::string path) {

	std::ifstream file(path.c_str());

	if (!file) {
		Logger::error("Reading file\n");
		return ("");
	}

	std::stringstream buffer;
	buffer << file.rdbuf();

	file.close();

	return (buffer.str());
}
