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
	clock_t start = clock();
	std::cout << "Before: ";
	for(size_t i=0; i < vec.size(); i++)
				std::cout << vec[i] << " ";
	std::cout << std::endl;
	algo.sorting(vec);
	std::cout << "After: ";
	for(size_t i=0; i < vec.size(); i++)
				std::cout << vec[i] << " ";
	clock_t endvec = clock() - start;
	clock_t startdeque = clock();
	std::cout << std::endl;
	algo.sorting(deque);
	clock_t enddeque = clock() - startdeque;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << ((float)endvec*1000)/CLOCKS_PER_SEC << " ms" <<std::endl;
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << ((float)enddeque*1000)/CLOCKS_PER_SEC << " ms" <<std::endl;
}