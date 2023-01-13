#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat	Michel("Michel", 5);
		Form		un("un", 5, 1);
		std::cout << un << std::endl;
		Michel.signForm(un);
		std::cout << un << std::endl;

		std::cout << std::endl;

		Form		deux("deux", 4, 12);
		std::cout << deux << std::endl;
		Michel.signForm(deux);
		std::cout << deux << std::endl;
		Michel.upgrade();
		Michel.signForm(deux);
		std::cout << deux << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		Form	b("b", 151, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		Form	b("b", 0, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		Form	c("c", 15, 242);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		Form	c("c", 15, -5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}