#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& wea ) {
	//std::cout << "constructor called HumanA" << std::endl;
	this->wea = &wea;
	this->name = name;
	return ;
}

HumanA::~HumanA( void ) {
	//std::cout << "Destructor called HumanA: " << this->name << std::endl;
	return ;
}

void	HumanA::attack( void ) {
	std::cout << this->name << " attacks with their " << this->wea->getType() << std::endl;
	return ;
}