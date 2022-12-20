#include "Weapon.hpp"

Weapon::Weapon( std::string type ) {
	//std::cout << "constructor called Weapon" << std::endl;
	this->setType(type);
	return ;
}

void	Weapon::setType( std::string	type ) {
	this->type = type;
	return ;
}

std::string	Weapon::getType( void ) const {
	return (this->type);
}

Weapon::~Weapon( void ) {
	//std::cout << "Destructor called Weapon: " << this->name << std::endl;
	return ;
}