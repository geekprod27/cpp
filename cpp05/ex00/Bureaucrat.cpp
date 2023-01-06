#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 0)
		throw std::exception();
	else if (grade > 150)
		throw std::exception();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */