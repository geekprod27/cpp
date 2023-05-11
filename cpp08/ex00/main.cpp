#include "easyfind.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "Iterator" << std::endl;
	try 
	{
		std::list<int>	l1;

		l1.push_back(10);
		l1.push_back(42);
		l1.push_back(65);
		l1.push_back(1);
		l1.push_back(-5);
		l1.push_back(8);
		l1.push_back(12);

		easyfind(l1, 42);
		std::cout << "Found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		std::list<int>	l1;

		l1.push_back(10);
		l1.push_back(42);
		l1.push_back(65);
		l1.push_back(1);
		l1.push_back(-5);
		l1.push_back(8);
		l1.push_back(12);

		easyfind(l1, 43);
		std::cout << "Found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	}

{
	std::cout << "const Iterator" << std::endl;
	try 
	{
		std::list<int>	l1;


		l1.push_back(10);
		l1.push_back(42);
		l1.push_back(65);
		l1.push_back(1);
		l1.push_back(-5);
		l1.push_back(8);
		l1.push_back(12);

		std::list<int> const	l2(l1);
		easyfind(l2, 42);
		std::cout << "Found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		std::list<int>	l1;


		l1.push_back(10);
		l1.push_back(42);
		l1.push_back(65);
		l1.push_back(1);
		l1.push_back(-5);
		l1.push_back(8);
		l1.push_back(12);

		std::list<int> const	l2(l1);
		easyfind(l2, 42);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
}
