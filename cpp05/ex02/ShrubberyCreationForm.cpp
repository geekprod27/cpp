#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
#include <ctype.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = " ";
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form("ShrubberyCreationForm", 145, 137)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getGradeExec() >= executor.getGrade())
	{
		if (this->getSign())
		{
			std::ofstream	ofs(this->_target.c_str());
			ofs  << "               ,@@@@@@@," << std::endl
				<< "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
				<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
				<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'" << std::endl
				<< "   %&&%&%&/%&&%@@\\@@/ /@@@8888888888'" << std::endl
				<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88\'" << std::endl
				<< "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
				<< "       |o|        | |         | |" << std::endl
				<< "       |.|        | |         | |" << std::endl
				<< "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl
				<< "" << std::endl
				<< "------------------------------------------------" << std::endl;
			ofs.close();
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