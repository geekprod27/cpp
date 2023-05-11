#include "Base.hpp"
#include <stdlib.h> 
#include <time.h>
#include <iostream>

Base * generate(void)
{
	std::srand(time(NULL));
	int nb = std::rand() % 3 + 1;

	switch (nb)
	{
	case 1:
	std::cout << "generated : A" << std::endl;
		return new A();
		break;
	case 2:
	std::cout << "generated : B" << std::endl;
		return new B();
		break;
	case 3:
	std::cout << "generated : C" << std::endl;
		return new C();
		break;
	
	default:
		break;
	}
	return (NULL);
}

void identify(Base* p)
{
	std::cout << "identify by pointer : ";

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Nop" << std::endl;
}

void identify(Base& p)
{
	std::cout << "identify by reference : ";

	try
	{
		Base test = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			Base test = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				Base test = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Nop" << std::endl;
			}
			
		}
		
	}
}