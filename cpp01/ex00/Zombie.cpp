#include "Zombie.hpp"

Zombie::Zombie( std::string	name ) {
	this->name = name;
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << "Destructor called Zombie: " << this->name << std::endl;
	return ;
}

void	Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}