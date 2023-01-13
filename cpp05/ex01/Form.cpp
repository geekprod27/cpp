#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name(" "), _gradesign(150), _gradeexec(150)
{
	this->_sign = false;
}

Form::Form(std::string	name, int gradesign, int gradeexec) : _name(name), _gradesign(gradesign), _gradeexec(gradeexec)
{
	this->_sign = false;
	if (this->_gradeexec > 150 || this->_gradesign > 150)
		throw Form::GradeTooLowException();
	if (this->_gradeexec < 1 || this->_gradesign < 1)
		throw Form::GradeTooHighException();
}

Form::Form( const Form & src ): _name(src._name), _gradesign(src._gradesign), _gradeexec(src._gradeexec)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_sign = rhs._sign;
	}
	return *this;
}

std::ostream & operator<<(std::ostream &o, Form const & rhs)
{
	o << "form " << rhs.getName() << ", gradesign " << rhs.getGradeSign() << ", gradeexec " << rhs.getGradeExec() << ", signed : " << rhs.getSign();
	return (o);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Form::getName() const
{
	return(this->_name);
}

bool			Form::getSign() const
{
	return(this->_sign);
}

int				Form::getGradeSign() const
{
	return(this->_gradesign);
}

int				Form::getGradeExec() const
{
	return(this->_gradeexec);
}

/* ************************************************************************** */

void			Form::beSigned(Bureaucrat &bu)
{
	if (bu.getGrade() <= this->getGradeSign())
		this->_sign = true;
	else
		throw Form::GradeTooLowException();
}