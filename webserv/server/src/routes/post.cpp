/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:57:13 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:57:13 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

bool isPathSafe(const std::string &fileName) {
	if (fileName.find("..") != std::string::npos) {
		return false;
	}
	return true;
}

bool isCGIFile(const std::string &fileName, const std::vector<std::string> &cgi_ext) {
	size_t dotPos = fileName.rfind('.');
	if (dotPos == std::string::npos) {
		return false;
	}
	std::string fileExt = fileName.substr(dotPos);
	for (size_t i = 0; i < cgi_ext.size(); ++i) {
		if (fileExt == cgi_ext[i]) {
			return true;
		}
	}
	return false;
}

void printFormData(formData &data) {
	Logger::debug("boundary: %s", data.boundary.c_str());
	Logger::debug("Content-Disposition: %s", data.dis.c_str());
	Logger::debug("name: %s", data.name.c_str());
	Logger::debug("filename: %s", data.filename.c_str());
	Logger::debug("Content-Type: %s", data.contentType.c_str());
	Logger::debug("fileContent:\n%s", data.fileContent.c_str());
}

bool parseFormData(HttpRequest &req, HttpResponse &res, formData &formData) {
	std::map<std::string, std::string>::iterator it = req.headers.find("content-type");
	if (it == req.headers.end()) {
		Logger::error("Error: No Content-Type header found.");
		handle500(res);
		return false;
	}

	std::string contentType = it->second;
	std::string boundaryPrefix = "boundary=";
	size_t pos = contentType.find("multipart/form-data");

	if (pos == std::string::npos) {
		Logger::error("Error: Content-Type is not multipart/form-data.");
		handle500(res);
		return false;
	}

	pos = contentType.find(boundaryPrefix);
	if (pos == std::string::npos) {
		Logger::error("Error: No boundary found in Content-Type.");
		handle500(res);
		return false;
	}

	formData.boundary = "--" + contentType.substr(pos + boundaryPrefix.length());

	std::string body = req.body;
	size_t start = body.find(formData.boundary);
	if (start == std::string::npos) {
		Logger::error("Error: Boundary not found in the body.");
		handle500(res);
		return false;
	}
	start += formData.boundary.length();

	size_t end = body.find("\r\n\r\n", start);
	if (end == std::string::npos) {
		Logger::error("Error: No double CRLF found (Headers missing or malformed).");
		handle500(res);
		return false;
	}

	std::string headers = body.substr(start, end - start);
	start = end + 4;

	pos = headers.find("Content-Disposition:");
	if (pos == std::string::npos) {
		Logger::error("Error: Content-Disposition header missing.");
		handle500(res);
		return false;
	}

	pos = headers.find("name=\"", pos);
	if (pos == std::string::npos) {
		Logger::error("Error: Name parameter missing in Content-Disposition.");
		handle500(res);
		return false;
	}
	size_t nameStart = pos + 6;
	size_t nameEnd = headers.find("\"", nameStart);
	formData.name = headers.substr(nameStart, nameEnd - nameStart);

	pos = headers.find("filename=\"", nameEnd);
	if (pos != std::string::npos) {
		size_t fileStart = pos + 10;
		size_t fileEnd = headers.find("\"", fileStart);
		formData.filename = headers.substr(fileStart, fileEnd - fileStart);
	}

	pos = headers.find("Content-Type:");
	if (pos != std::string::npos) {
		size_t typeStart = pos + 14;
		size_t typeEnd = headers.find("\r\n", typeStart);
		formData.contentType = headers.substr(typeStart, typeEnd - typeStart);
	}

	end = body.find(formData.boundary, start);
	if (end == std::string::npos) {
		Logger::error("Error: No closing boundary found.");
		handle500(res);
		return false;
	}

	formData.fileContent = body.substr(start, end - start - 2);

	return true;
}

bool insertFileIntoDirTree(dir &root, const file &newFile) {

	std::string normalizedRoot = root.path;
	if (!normalizedRoot.empty() && normalizedRoot[normalizedRoot.size() - 1] == '/')
		normalizedRoot = normalizedRoot.substr(0, normalizedRoot.size() - 1);

	if (newFile.path == normalizedRoot || newFile.path.find(normalizedRoot + "/") != 0) {
		return false;
	}

	size_t pos = newFile.path.find('/', normalizedRoot.size() + 1);
	if (pos == std::string::npos) {
		root.files.push_back(newFile);
		return true;
	}

	std::string nextDirName = newFile.path.substr(normalizedRoot.size() + 1, pos - normalizedRoot.size() - 1);
	std::string subPath = normalizedRoot + "/" + nextDirName;

	for (size_t i = 0; i < root.dirs.size(); ++i) {
		if (root.dirs[i].path == subPath) {
			return insertFileIntoDirTree(root.dirs[i], newFile);
		}
	}
	dir newSubDir;
	newSubDir.path = subPath;
	root.dirs.push_back(newSubDir);

	return insertFileIntoDirTree(root.dirs.back(), newFile);
}




void handleRegularLocation(HttpRequest &req, HttpResponse &res, server &server, location &loc, int clientFd) {
	std::string path = loc.root + "/" + loc.index;

	SearchResult result;
	if (findInDirTree(loc.tree, path, result) && !result.isDir) {
		executeSkript(req, res, server, clientFd, result.foundFile);
		return;
	}
	handle404(res);
}


void routeRequestPOST(HttpRequest &req, HttpResponse &res, server &server, location &loc, int clientFd) {
	if (loc.regularLocation) {
		handleRegularLocation(req, res, server, loc, clientFd);
		return;
	}

	if (req.headers["content-type"].find("multipart/form-data") != std::string::npos) {
		std::string uploadDir;


		if (loc.root.size() != 0) {
			uploadDir = loc.root + "/";
		} else {
			uploadDir = server.root + "/";
		}

		formData form;


		if (parseFormData(req, res, form) == false) {
			handle400(res);
			return;
		}

		if (uploadDir.empty()) {
			Logger::error("Upload directory is not set.");
			handle500(res);
			return;
		}

		std::string fileName = form.filename;
		if (fileName.empty() || !isPathSafe(fileName)) {
			Logger::error("Invalid or unsafe filename");
			handle400(res);
			return;
		}

		std::string filePath = uploadDir + fileName;
		std::ofstream outfile(filePath.c_str(), std::ios::binary);

		if (!outfile) {
			Logger::error("Failed to open file for writing: %s", filePath.c_str());
			handle500(res);
			return;
		}

		outfile.write(form.fileContent.c_str(), form.fileContent.size());
		outfile.close();

		file newFile;

		newFile.path = filePath;
		newFile.contentType = getContentType(getFileExtension(filePath));

		if (isCGIFile(fileName, loc.cgi_ext)) {

			if (!setsetExecutable(filePath)) {
				Logger::error("Failed to set file as executable: %s", filePath.c_str());
			}
		}


		dir &targetTree = loc.root.empty() ? server.serverContex.tree : loc.tree;

		if (!insertFileIntoDirTree(targetTree, newFile)) {
			Logger::error("Failed to insert uploaded file into tree structure: %s", filePath.c_str());
			handle500(res);
			return;
		}

		res.statusCode = 201;
		res.statusMessage = "Created";
		res.body = "File uploaded successfully.";
	} else {
		if (req.body.size() == 0) {
			res.statusCode = 200;
			res.statusMessage = "OK";
			res.body = "";
		} else {
			res.statusCode = 200;
			res.statusMessage = "OK";
		}
	}

}
