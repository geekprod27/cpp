#include "harl.hpp"

harl::harl( void ) {
	//std::cout << "constructor called harl" << std::endl;
	return ;
}

harl::~harl( void ) {
	//std::cout << "Destructor called harl" << std::endl;
	return ;
}

void	harl::complain( std::string level )
{
	std::string	lvl[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void	(harl::*f[4])(void) = {
		&harl::debug,
		&harl::info,
		&harl::warning,
		&harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (lvl[i] == level)
			(this->*f[i])();
	}
}

void	harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	harl::error( void )
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}