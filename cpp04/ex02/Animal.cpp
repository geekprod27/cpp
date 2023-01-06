#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	this->type = " ";
	std::cout << "Constructor Animal called" << std::endl;
}

Animal::Animal( const Animal & src )
{
	*this = src;
	std::cout << "Copy constructor Animal called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Destructor Animal called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound( void ) const
{
	std::cout << "Ceci est un bruit d animal" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Animal::getType( void ) const
{
	return(this->type);
}

/* ************************************************************************** */