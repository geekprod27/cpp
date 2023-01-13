#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void) rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
Form *newrobot(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *newshrub(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *newpres(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	Form *ret = NULL;

	std::string	lvl[3] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};

	Form	*(*f[3])(std::string target) = {
		&newrobot,
		&newshrub,
		&newpres
	};

	for (int i = 0; i < 3; i++)
	{
		if (lvl[i] == name)
			ret = f[i](target);
	}

	if (ret == NULL)
		std::cerr << "Intern : name invalid" << std::endl;
	else
		std::cout << "Intern creates " << name << std::endl;
	return (ret);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */