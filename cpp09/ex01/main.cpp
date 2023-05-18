#include <stack>
#include <iostream>

int calc(int un, int deux, char ope)
{
	switch (ope)
	{
	case ('/'):
		if (deux == 0)
			return (0);
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
	std::stack<int> input_int;
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
			un = input_int.top();
			input_int.pop();
			deux = input_int.top();
			input_int.pop();
			input_int.push(calc(deux, un, argv[1][i]));
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