#include "RobotomyRequestForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
#include <ctype.h>
#include <stdlib.h> 
#include <time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
	this->_target = " ";
}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form("RobotomyRequestForm", 72, 45)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getGradeExec() >= executor.getGrade())
	{
		if (this->getSign())
		{
			std::cout << "* BUIT DE PERCEUSE *" << std::endl;
			std::srand(time(NULL));
			if (std::rand() % 100 + 1 >= 50)
				std::cout << this->_target << " a ete robotomisee" << std::endl;
			else
				std::cout << "L operation de robotomisation a echoue" << std::endl;
		}
		else
			throw Form::NotSignedException();
	}
	else
		throw Form::GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */