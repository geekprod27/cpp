#include "RPN.hpp"

int calc(int un, int deux, char ope)
{
	switch (ope)
	{
	case ('/'):
		if (deux == 0)
			throw ("Error : division by 0");
		else
			return (un / deux);
		break;
	case ('*'):
		return (un * deux);
		break;
	case ('-'):
		return (un - deux);
		break;
	case ('+'):
		return (un + deux);
		break;
	default:
		return(0);
		break;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[31musage ./RPN \"input\"\033[0m" << std::endl; 
		return (1);
	}
	std::stack<int, std::list<int> > input_int;
	int i = 0;
	while(argv[1][i])
	{
		if (argv[1][i] == ' ')
		{
			i++;
			continue;
		}
		if (isdigit(argv[1][i]))
		{
			input_int.push(argv[1][i] - '0');
		}
		else if (argv[1][i] == '/' || argv[1][i] == '*' || argv[1][i] == '+' || argv[1][i] == '-')
		{
			if (input_int.size() < 2)
			{
				std::cerr << "\033[31mError\033[0m" << std::endl; 
				return (1);
			}
			int un, deux;
			deux = input_int.top();
			input_int.pop();
			un = input_int.top();
			input_int.pop();
			try{
				input_int.push(calc(un, deux, argv[1][i]));
			}
			catch(char const* exep)
			{
				std::cout << exep <<std::endl;
				return (1);
			}
		}
		else
		{
			std::cerr << "\033[31mError\033[0m" << std::endl; 
			return (1);
		}
		i++;
	}
	if (input_int.size() == 1)
		std::cout << "Result is " << input_int.top() << std::endl;
	else
		std::cerr << "\033[31mError\033[0m" << std::endl;
}