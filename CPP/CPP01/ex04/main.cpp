/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:01:02 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/08 13:53:20 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

bool	replaceLoop(std::ifstream &inFile, std::ofstream &OutFile, std::string str1, std::string str2) {
	std::string	line;
	size_t		pos;

	while (getline(inFile, line))
	{
		if (inFile.fail() && !inFile.eof()) {
			return (std::cout << "read error\n", true);
		}
		while (1)
		{
			pos = line.find(str1);
			if (pos != std::string::npos) {
				std::string start = line.substr(0, pos);
				std::string end = line.substr(pos + str1.length());
				line = start + str2 + end;
			} else {
				break ;
			}
		}
		OutFile << line << std::endl;
		if (OutFile.fail())
			return (std::cout << "write error\n", true);
	}
	return (false);
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		return (std::cout << "bad arg number\n", 1);
	}
	std::ifstream inFile(argv[1]);
	if (!inFile.is_open()) {
		std::cout << "can't open in file\n";
		return (1);
	}
	std::string outFilePath = std::string(argv[1]) + ".replace";
	std::ofstream outFile(outFilePath.c_str());
	if (!outFile.is_open()) {
		std::cout << "can't open in file\n";
	}
	if (!outFile) {
		inFile.close();
		return (1);
	}
	if (replaceLoop(inFile, outFile, argv[2], argv[3])) {
		inFile.close();
		outFile.close();
		return (1);
	}
	inFile.close();
	outFile.close();
	return (0);
}
