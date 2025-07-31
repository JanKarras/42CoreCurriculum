#include "../include/BitcoinExchange.hpp"

std::string trim(const std::string &str) {
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(str[start])){
		start++;
	}

	while (end > start && std::isspace(str[end - 1])) {
		end--;
	}

	return (str.substr(start, end - start));
}

bool check_files(std::string fileName) {
	std::ifstream file(fileName.c_str());
	if (!file) {
		std::cerr << "Could not open file: " << fileName << std::endl;
		return (false);
	}
	file.close();
	return (true);
}

std::map<std::string, float> createDatabase( void ) {
	std::map<std::string, float> database;
	std::ifstream file("data.csv");
	if (!file) {
		std::cerr << "Could not open file: data.csv\n";
		database["error"] = 1;
		return (database);
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		std::string valueStr;
		float value;
		if (std::getline(ss, date, ',') && std::getline(ss, valueStr)) {
			std::istringstream valueStream(valueStr);
			valueStream >> value;

			if (valueStream.fail()) {
				std::cerr << "Invalid value in line: " << line << "\n";
				continue;
			}
			database[date] = value;
		} else {
			std::cerr << "Malformed line: " << line << std::endl;
		}
	}
	file.close();
	return (database);
}

bool checkDate(std::string date, std::string *datePtr) {
	if (date.length() != 11) {
		return (false);
	}
	for (size_t i = 0; i < 4; i++) {
		if (date[i] < '0' || date[i] > '9')
			return (false);
	}
	if (date[4] != '-') {
		return (false);
	}
	for (size_t i = 5; i < 7; i++) {
		if (i == 5 && date[i] > '1')
			return (false);
		if (i == 6 && date[i] > '2')
			return (false);
		if (date[i] < '0' || date[i] > '9')
			return (false);
	}
	if (date[7] != '-') {
		return (false);
	}
	for (size_t i = 8; i < 10; i++) {
		if (i == 8 && date[i] > '3') {
			return (false);
		}
		if (i == 8 && date[i + 1] == '0' && date[i] == '0'){
			return (false);
		}
		if (i == 9 && date[i] > '1' && date[i - 1] == '3') {
			return (false);
		}
		if (date[i] < '0' || date[i] > '9')
			return (false);
	}
	if (date[10] != ' ') {
		return (false);
	}
	*datePtr = trim(date);
	return (true);
}

bool checkValue(std::string valueStr, float *valuePtr, std::string line) {
	if (valueStr.length() < 1) {
		return(false);
	}
	if (valueStr[0] != ' ') {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	int dotCount = 0;
	for (size_t i = 1; i < valueStr.length(); i++) {
		if ((valueStr[i] < '0' || valueStr[i] > '9') && valueStr[i] != '.' && valueStr[i] != '-') {
			return (false);
		}
		if (valueStr[i] == '.') {
			dotCount++;
		}
	}
	if (dotCount > 1) {
		return (false);
	}

	valueStr = trim(valueStr);
	std::istringstream valueStream(valueStr);
	float value;
	valueStream >> value;

	if (valueStream.fail()) {
		return (false);
	}

	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}

	*valuePtr = value;
	return (true);
}


bool checkLine(std::string line, float *valuePtr, std::string *datePtr) {
	std::istringstream ss(line);
	std::string date;
	std::string valueStr;

	if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
		if (!checkDate(date, datePtr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			return (false);
		}
		if (!checkValue(valueStr, valuePtr, line)) {
			return (false);
		}
	} else {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	return (true);
}


bool getNextSmallestDate(std::map<std::string, float> database, std::string *date) {
	std::string currentDate = *date;
	std::string nextSmallestDate;
	bool found = false;

	for (std::map<std::string, float>::iterator it = database.begin(); it != database.end(); ++it) {
		if (it->first < currentDate && (!found || it->first > nextSmallestDate)) {
			nextSmallestDate = it->first;
			found = true;
		}
	}

	if (found) {
		*date = nextSmallestDate;
		return (true);
	}
	return (false);
}

bool printPrices(std::map<std::string, float> database, std::string fileName) {
	std::ifstream file(fileName.c_str());
	if (!file) {
		std::cerr << "Could not open file: data.csv\n";
		return (false);
	}
	float value;
	std::string date;
	std::string line;
	while (std::getline(file, line)) {
		value = 0;
		date = "";
		if (!checkLine(line, &value, &date)) {
			continue;
		}
		std::map<std::string, float>::iterator it = database.find(date);
		if (it != database.end()) {
			std::cout	<< date << " => " << value << " = " << value * it->second << std::endl;
		} else {
			if (getNextSmallestDate(database, &date)) {
				it = database.find(date);
				std::cout	<< date << " => " << value << " = " << value * it->second << std::endl;
			} else {
				std::cout << "No data available for the date: " << date << std::endl;
			}
		}
	}
	return (true);
}

int main (int argc, char **argv) {
	if (argc != 2) {
		std::cout << "bad arg num\n";
		return (1);
	}

	if (!check_files("data.csv") || !check_files(argv[1])) {
		std::cerr << "Error: Required files not accessible\n";
		return (1);
	}

	std::map<std::string, float> database = createDatabase();
	if (database["error"] == 1) {
		database.clear();
		return (1);
	}

	if (!printPrices(database, argv[1])) {
		database.clear();
		return (1);
	}

	return (0);
}
