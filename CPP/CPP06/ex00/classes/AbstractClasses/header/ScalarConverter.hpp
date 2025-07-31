#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include "../../../include/libs.hpp"
#include "../../ExceptionClasses/header/NonePrintableException.hpp"

enum type {
	CHAR = 0,
	INT = 1,
	DOUBLE = 2,
	FLOAT = 3,
	POSITIVE_INF = 4,
	NEGATIVE_INF = 5,
	NANF = 6
};

class ScalarConverter {
	private:
		ScalarConverter( void );
	public:
		virtual ~ScalarConverter( void );
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		static void convert(std::string literal);
};

#endif
