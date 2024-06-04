#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

int my_stoi(const std::string& str) {
    std::istringstream iss(str);
    int result;
    if (!(iss >> result) || !iss.eof())
        throw std::invalid_argument("stoi");
    return result;
}

float my_stof(const std::string& str) {
    char* endptr;
    const char* cstr = str.c_str();
    float result = strtof(cstr, &endptr);
    if (*endptr != '\0')
        throw std::invalid_argument("stof");
    return result;
}

double my_stod(const std::string& str) {
    char* endptr;
    const char* cstr = str.c_str();
    double result = strtod(cstr, &endptr);
    if (*endptr != '\0')
        throw std::invalid_argument("stod");
    return result;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]) && literal[0] >= 32 && literal[0] <= 126)
	{
		std::cout << "its a char" << std::endl;
		char c = literal[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
	{
		try
		{
			int i = my_stoi(literal);
			std::cout << "its an int" << std::endl;
			if (i < 32 || i > 126)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(i) << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
			return;
		}
		catch (std::exception &e)
		{
		}
		try
		{
			float f = my_stof(literal);
			std::cout << "its a float" << std::endl;
			if (f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity() || std::isnan(f))
				std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: " << f << std::endl << "double: " << static_cast<double>(f) << std::endl;
			else
			{
				if (f < 32 || f > 126)
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: " << static_cast<char>(static_cast<int>(f)) << std::endl;
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << std::endl;
			}
			return;
		}
		catch (std::exception &e)
		{
		}
		try
		{
			double d = my_stod(literal);
			std::cout << "its a double" << std::endl;
			if (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity() || std::isnan(d))
				std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
			else
			{
				if (d < 32 || d > 126)
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: " << static_cast<char>(static_cast<int>(d)) << std::endl;
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			}
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
		catch (std::exception &e)
		{
		}
		std::cout << "invalid input" << std::endl;
	}
}

