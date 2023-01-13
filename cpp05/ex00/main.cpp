#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat	Michel("Michel", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	Michel("Michel", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	Jack("Jack", 150);
		std::cout << Jack << std::endl;
		Jack.downgrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	Jack("Jack", 10);
		std::cout << Jack << std::endl;
		Jack.upgrade();
		std::cout << Jack << std::endl;
		Jack.upgrade();
		Jack.upgrade();
		Jack.upgrade();
		Jack.upgrade();
		Jack.upgrade();
		Jack.upgrade();
		Jack.upgrade();
		Jack.upgrade();
		Jack.upgrade();
		std::cout << Jack << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	Jack("Jack", 141);
		std::cout << Jack << std::endl;
		Jack.downgrade();
		std::cout << Jack << std::endl;
		Jack.downgrade();
		Jack.downgrade();
		Jack.downgrade();
		Jack.downgrade();
		Jack.downgrade();
		Jack.downgrade();
		Jack.downgrade();
		Jack.downgrade();
		Jack.downgrade();
		std::cout << Jack << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}