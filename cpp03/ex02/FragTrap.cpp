#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	std::cout << "Constructor called FragTrap" << std::endl;
	this->name = " ";
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamages = 30;
}

FragTrap::FragTrap( const FragTrap & src )
{
	*this = src;
	std::cout << "Copy constructor called FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string named)
{
	std::cout << "Constructor called FragTrap" << std::endl;
	this->name = named;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamages = 30;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "Destructor called FragTrap" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.name;
		this->HitPoints = rhs.HitPoints;
		this->EnergyPoints = rhs.EnergyPoints;
		this->AttackDamages = rhs.AttackDamages;
	}
	return *this;
}

/* ************************************************************************** */

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->name << " hight fives ?" << std::endl;
}