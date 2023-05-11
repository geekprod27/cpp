#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name(" ")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src.getName())
{
	*this = src;
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
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream & operator<<(std::ostream &o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string		Bureaucrat::getName() const
{
	return (this->_name);
}

void	Bureaucrat::upgrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::downgrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}


/* ************************************************************************** */

void			Bureaucrat::signForm(Form &fo)
{
	try
	{
		fo.beSigned(*this);
		std::cout << this->getName() << " signed " << fo.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn’t sign " << fo.getName() << " because " << e.what() << std::endl;
	}
	
}

void			Bureaucrat::executeForm(Form const & fo)
{
	try
	{
		fo.execute(*this);
		std::cout << this->getName() << " executed " << fo.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn’t executed " << fo.getName() << " because " << e.what() << std::endl;
	}
}