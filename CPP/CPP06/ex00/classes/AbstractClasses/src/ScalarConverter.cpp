/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:25:27 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:25:27 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {
	if (DEBUG) {
		std::cout << "ScalarConverter standart constructor called\n";
	}
}

ScalarConverter::~ScalarConverter( void ) {
	if (DEBUG) {
		std::cout << "ScalarConverter standart deconstructor called\n";
	}
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	if (DEBUG) {
		std::cout << "ScalarConverter copy constructor called\n";
	}
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (DEBUG) {
		std::cout << "ScalarConverter copy assigment constructor called\n";
	}
	if (this != &other) {

	}
	return (*this);
}

int stringToInt(const std::string &str) {
	std::istringstream iss(str);
	int num;
	iss >> num;
	if (iss.fail()) {
		throw std::invalid_argument("Invalid argument for conversion to int");
	}
	return num;
}

double stringToDouble(const std::string& str) {
	const char* cstr = str.c_str();
	char* end;
	double value = std::strtod(cstr, &end);

	if (*end != '\0') {
		throw std::invalid_argument("Invalid string to convert to double");
	}
	return value;
}

float stringToFloat(std::string& str) {
	if (!str.empty() && str[str.length() - 1] == 'f') {
		str = str.substr(0, str.length() - 1);
	}
	std::stringstream ss(str);
	float value;
	ss >> value;

	if (ss.fail() || !ss.eof()) {
		throw std::invalid_argument("Invalid string to convert to float");
	}
	return value;
}

type getType(std::string literal, size_t *precision) {
	size_t	afterDot = 0;
	size_t	i = 0;
	bool	hasChar = false;
	bool	hasDot = false;

	if (literal.compare("-inff") == 0 || literal.compare("-inf") == 0) {
		return (NEGATIVE_INF);
	} else if (literal.compare("+inff") == 0 || literal.compare("+inf") == 0) {
		return (POSITIVE_INF);
	} else if (literal.compare("nanf") == 0 || literal.compare("nan") == 0) {
		return (NANF);
	}
	if (literal[0] == '-') {
		i++;
	}

	while (literal[i])
	{
		if (hasDot) {
			afterDot++;
		}
		if (literal[i] >= '0' && literal[i] <= '9') {
			;
		} else if (literal[i] == '.') {
			hasDot = true;
		} else {
			hasChar = true;
		}
		i++;
	}
	if (hasDot && literal[i - 1] != 'f') {
		if (afterDot) {
			*precision = afterDot;
		}
		return (DOUBLE);
	} else if (hasDot && literal[i - 1] == 'f') {
		if (afterDot) {
			*precision = afterDot - 1;
		}
		return (FLOAT);
	} else if (hasChar) {
		return (CHAR);
	} else {
		return (INT);
	}
}

bool checkForNonePrintable(std::string literal) {
	size_t i;

	i = 0;
	while (literal[i])
	{
		if (literal[i] < 32 || literal[i] > 126 ) {
			return (true);
		}
		i++;
	}
	return (false);
}

bool checkCharNonePrint(char c) {
	if (c < 32 || c > 126 ) {
		return (true);
	}
	return (false);
}

void ScalarConverter::convert(std::string literal) {
	size_t precision = 0;
	type type = getType(literal, &precision);
	int _int = 0;
	bool _intImpossible = false;
	char _char = '\0';
	bool _charImpossible = false;
	bool _charNonPrint = false;
	float _float = 0.0f;
	bool _floatImpossible = false;
	double _double = 0.0;
	bool _doubleImpossible = false;

	switch (type)
	{
	case 0:
		{
			_char = literal[0];
			_int = static_cast<int>(_char);
			_float = static_cast<float>(_char);
			_double = static_cast<double>(_char);
		}
		break;
	case 1:
		{
			_int = stringToInt(literal);
			_char = static_cast<char>(_int);
			_float = static_cast<float>(_int);
			_double = static_cast<double>(_int);
		}
		break;
	case 2:
		{
			_double = stringToDouble(literal);
			_char = static_cast<char>(_double);
			_int = static_cast<int>(_double);
			_float = static_cast<float>(_double);
		}
		break;
	case 3:
		{
			_float = stringToFloat(literal);
			_double = static_cast<double>(_float);
			_int = static_cast<int>(_float);
			_char = static_cast<char>(_float);
		}
		break;
	case 4:
		_float = std::numeric_limits<float>::infinity();
		_double = std::numeric_limits<double>::infinity();
		_charImpossible = true;
		_intImpossible = true;
		break;
	case 5:
		_float = -std::numeric_limits<float>::infinity();
		_double = -std::numeric_limits<double>::infinity();
		_charImpossible = true;
		_intImpossible = true;
		break;
	case 6:
		_float = std::numeric_limits<float>::quiet_NaN();
		_double = std::numeric_limits<double>::quiet_NaN();
		_charImpossible = true;
		_intImpossible = true;
		break;
	default:
		break;
	}
	if (checkCharNonePrint(_char)) {
		_charNonPrint = true;
	}
	std::cout << "char: ";
	if (_charImpossible) {
		 std::cout << "impossible\n";
	} else if (_charNonPrint) {
		std::cout << "Non printable\n";
	} else {
		std::cout << "'" << _char << "'" << std::endl;
	}
	std::cout << "int: ";
	if (_intImpossible) {
		std::cout << "impossible\n";
	} else {
		std::cout << _int << std::endl;
	}
	std::cout << "float: ";
	if (_floatImpossible) {
		std::cout << "impossible\n";
	} else {
		std::cout << std::fixed << std::setprecision(precision) << _float << "f\n";
	}
	std::cout << "double: ";
	if (_doubleImpossible) {
		std::cout << "impossible\n";
	} else {
		std::cout << std::fixed << std::setprecision(precision) << _double << std::endl;
	}
}

