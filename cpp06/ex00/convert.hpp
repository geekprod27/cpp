#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <stdexcept>

typedef struct s_convert
{
	int		type; // char = 0 / int = 1 / float = 2 / double = 3
	char	charval;
	int		intval;
	float	floatval;
	double	doubleval;
}	convert;


class NonDiplayException : public std::exception
{
	public:
	
		virtual const char * what() const throw()
		{
			return ("Non displayable");
		}
};

class ImpossibleException : public std::exception
{
	public:
	
		virtual const char * what() const throw()
		{
			return ("impossible");
		}
};

char toChar(convert *data);
int toInt(convert *data);
float toFloat(convert *data);
double toDouble(convert *data);

#endif