/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeExecutable.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:56:50 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:56:50 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

bool setsetExecutable(std::string &filePath) {
	pid_t pid = fork();

	if (pid == -1) {
		Logger::error("Fork failed");
		return false;
	}

	if (pid == 0) {
		char *argv[] = { (char *)"/bin/chmod", (char *)"755", (char *)filePath.c_str(), NULL };
		execve(argv[0], argv, NULL);
		Logger::error("execve failed for chmod");
		_exit(1);
	}

	int status;
	if (waitpid(pid, &status, 0) == -1) {
		Logger::error("waitpid failed");
		return false;
	}

	if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
		return true;
	} else {
		Logger::error("chmod failed with exit code %d", WEXITSTATUS(status));
		return false;
	}
}

