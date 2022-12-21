#include "harl.hpp"

int main( void )
{
	harl harl;

	std::cout << "Debug :" << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl;

	std::cout << "Info :" << std::endl;
	harl.complain("INFO");

	std::cout << std::endl;

	std::cout << "Warning :" << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl;

	std::cout << "Error :" << std::endl;
	harl.complain("ERROR");
}