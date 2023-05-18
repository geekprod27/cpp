#include "PmergeMe.hpp"

void	init(std::vector<int> *vec, std::deque<int> *deque, char **input)
{
	int i = 1;
	int value;
	while (input[i])
	{
		value = atoi(input[i]);
		if (value < 0)
		{
			std::cerr << "\033[31mError\033[0m" << std::endl;
			exit(1);
		}
		deque->push_back(value);
		vec->push_back(value);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "\033[31mError\033[0m" << std::endl; 
		return (1);
	}
	PmergeMe algo;
	std::vector<int> vec;
	std::deque<int> deque;
	init(&vec, &deque, argv);
	std::cout << "Before vec: ";
	for(size_t i=0; i < vec.size(); i++)
				std::cout << vec[i] << " ";
	std::cout << std::endl;
	algo.sorting(vec);
	std::cout << "After vec: ";
	for(size_t i=0; i < vec.size(); i++)
				std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << "Before deque: ";
	for(size_t i=0; i < deque.size(); i++)
				std::cout << deque[i] << " ";
	std::cout << std::endl;
	algo.sorting(deque);
	std::cout << "After deque: ";
	for(size_t i=0; i < deque.size(); i++)
				std::cout << deque[i] << " ";
	std::cout << std::endl;
}