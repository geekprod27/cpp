#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	std::cout << "Constructor called ScavTrap" << std::endl;
	this->name = " ";
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamages = 20;

}

ScavTrap::ScavTrap(std::string named)
{
	std::cout << "Constructor called ScavTrap" << std::endl;
	this->name = named;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamages = 20;

}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	*this = src;
	std::cout << "Copy constructor called ScavTrap" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called ScavTrap" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
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

void	ScavTrap::attack(const std::string& target)
{
	if (this->HitPoints > 0 && this->EnergyPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamages << " points of damage !" << std::endl;
		this->EnergyPoints--;
	}
	else
		std::cout << "Action \"attack\" impossible !" << std::endl; 
}

void 	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->name << " is on Gate keeper" << std::endl;
}