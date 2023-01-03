#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() : HitPoints(10), EnergyPoints(10), AttackDamages(0)
{
	this->name = " ";
	std::cout << "Constructor called ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : HitPoints(10), EnergyPoints(10), AttackDamages(0)
{
	this->name = name;
	std::cout << "Constructor called ClapTrap" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	*this = src;
	std::cout << "Copy constructor called ClapTrap" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called ClapTrap" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->HitPoints > 0 && this->EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamages << " points of damage !" << std::endl;
		this->EnergyPoints--;
	}
	else
		std::cout << "Action \"attack\" impossible !" << std::endl; 
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HitPoints > 0 && this->EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " be Repaired of " << amount << " point of hit" << std::endl;
		this->HitPoints += amount;
	}
	else
		std::cout << "Action \"beRepaired\" impossible !" << std::endl; 
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " take " << amount << " point of damage" << std::endl;
		if (amount <= this->HitPoints)
			this->HitPoints -= amount;
		else
			this->HitPoints = 0;
	}
	else
		std::cout << "Action \"takeDamage\" impossible ! (already dead)" << std::endl; 
}