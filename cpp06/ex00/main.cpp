# include <iostream>
# include <string>
# include <sstream>
#include <cstdlib>

# include "convert.hpp"

void aff(convert *data)
{
	std::cout << "char : ";
	try
	{
		std::cout << toChar(data) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "int : ";
	try
	{
		std::cout << toInt(data) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "float : ";
	try
	{
		std::cout << toFloat(data) << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "double : ";
	try
	{
		std::cout << toDouble(data) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	identi(convert *data, std::string str)
{
	int i;
	float f;
	double d;

	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		data->floatval = static_cast<float>(atof(str.c_str()));
		data->type = 2;
		return 1;
	}
	else if (str == "-inf" || str == "+inf" || str == "nan")
	{
		data->doubleval = atof(str.c_str());
		data->type = 3;
		return 1;
	}
	std::stringstream s(str);

	if (s >> i && s.rdbuf()->in_avail() == 0)
	{
		data->intval = i;
		data->type = 1;
		return 1;
	}
	std::stringstream s1(str);
	if (s1 >> f && s1.rdbuf()->in_avail() == 0)
	{
		data->floatval = f;
		data->type = 2;
		return 1;
	}
	std::stringstream s2(str);
	if (s2 >> d && s2.rdbuf()->in_avail() == 0)
	{
		data->doubleval = d;
		data->type = 3;
		return 1;
	}
	return 0;
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Utiliser : ./convert <number>" << std::endl;
		return 1;
	}
	std::string s(argv[1]);
	convert data;

	if (s.size() == 1 && !isdigit(s[0]))
	{
		data.type = 0;

		std::stringstream str(s);
		str >> data.charval;
		data.intval = static_cast<int>(data.charval);
	}
	else if (!identi(&data, s))
	{
		std::cout << "Invalid input" << std::endl;
		return 1;
	}
	std::cout << data.type << std::endl;
	aff(&data);
} 