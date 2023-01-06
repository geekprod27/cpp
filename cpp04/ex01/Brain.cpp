#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Constructor Brain called" << std::endl;
}

Brain::Brain( const Brain & src )
{
	*this = src;
	std::cout << "Copy constructor Brain called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Destructor Brain called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void		Brain::setIdeas( std::string ide, int id )
{
	if (id >= 100 || id < 0)
		return ;
	this->ideas[id] = ide;
}

std::string	Brain::getIdeas( int id )
{
	if (id >= 100 || id < 0)
		return ("");
	return (this->ideas[id]);
}

/* ************************************************************************** */