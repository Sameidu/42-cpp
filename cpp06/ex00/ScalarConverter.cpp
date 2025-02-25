#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string input) {
	(void)input;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return *this;
}

int searchConversion(std::string input) {
	if (input.length() == 1 && !isdigit(input[0]))
		return 0;
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
		return 4;

	int i = 0;
	int dot = 0;

	if (input[i] == '-' || input[i] == '+')
		i++;
	if (!isdigit(input[i]))
		return -1;
	while (isdigit(input[i]))
		i++;
	if (input[i] == '.') {
		dot++;
		i++;
		while (isdigit(input[i]))
			i++;
	}
	if (!input[i] && input[i - 1] != '.')
		return (dot == 0) ? 1 : 3;
	if (input[i] == 'f' && !input[i + 1] && dot == 1 && isdigit(input[i - 1]))
		return 2;
	return -1;
}


void convertChar(std::string const &input) {
	char convert = input[0];

	std::cout << "char: ";
	if (isprint(convert))
		std::cout << "'" << convert << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(convert) << std::endl;
	std::cout << "float: " << static_cast<float>(convert) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(convert) << ".0" << std::endl;
}

void convertInt(std::string const &input) {
	int convert = std::atoi(input.c_str());

	std::cout << "INT_CONVERT" << std::endl;
	std::cout << "char: ";
	if (isprint(convert))
		std::cout << "'" << static_cast<char>(convert) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << convert << std::endl;
	std::cout << "float: " << static_cast<float>(convert) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(convert) << ".0" << std::endl;
}

void convertFloat(std::string const &input) {
	float convert = std::atof(input.c_str());

	std::cout << "FLOAT_CONVERT" << std::endl;
	std::cout << "char: ";
	if (isprint(convert))
		std::cout << "'" << static_cast<char>(convert) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(convert) << std::endl;
	std::cout << "float: " << convert << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(convert) << std::endl;
}

void convertDouble(std::string const &input) {
	double convert = std::atof(input.c_str());

	std::cout << "DOUBLE_CONVERT" << std::endl;
	std::cout << "char: ";
	if (isprint(convert))
		std::cout << "'" << static_cast<char>(convert) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(convert) << std::endl;
	std::cout << "float: " << static_cast<float>(convert) << "f" << std::endl;
	std::cout << "double: " << convert << std::endl;
}

void convertSpecial(std::string const &input) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "nan" || input == "nanf"){
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (input == "+inf" || input == "+inff") {
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	} else {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(std::string const &input) {
	int convert = searchConversion(input);

	switch (convert) {
		case 0:
			convertChar(input);
			break;
		case 1:
			convertInt(input);
			break;
		case 2:
			convertFloat(input);
			break;
		case 3:
			convertDouble(input);
			break;
		case 4:
			convertSpecial(input);
			break;
		default:
			std::cerr << "Error: Invalid input" << std::endl;
			break;
	}
}