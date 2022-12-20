#include "HumanB.hpp"

HumanB::HumanB( std::string name, Weapon& wea ) {
	//std::cout << "constructor called HumanB" << std::endl;
	this->wea = &wea;
	this->name = name;
	return ;
}

HumanB::HumanB( std::string name ) {
	//std::cout << "constructor called HumanB" << std::endl;
	this->name = name;
	return ;
}

void	HumanB::setWeapon( Weapon& wea ) {
	//std::cout << "constructor called HumanB" << std::endl;
	this->wea = &wea;
	return ;
}

void	HumanB::attack( void ) {
	if (this->wea)
		std::cout << this->name << " attacks with their " << this->wea->getType() << std::endl;
	else
		std::cout << this->name << " attacks with nothing" << std::endl;
	return ;
}

HumanB::~HumanB( void ) {
	//std::cout << "Destructor called HumanB: " << this->name << std::endl;
	return ;
}