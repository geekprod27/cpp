#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern inte;
	Bureaucrat boss("boss", 1);
	
	
	Bureaucrat buss("buss", 144);
	Form	*a = inte.makeForm("shrubbery creation", "jardin");

	buss.executeForm(*a);

	boss.executeForm(*a);
	buss.signForm(*a);
	boss.executeForm(*a);

	delete a;
	std::cout << std::endl;

	Bureaucrat bass("bass", 72);
	Form	*b = inte.makeForm("robotomy request", "coucou");

	bass.executeForm(*b);

	boss.executeForm(*b);
	bass.signForm(*b);
	boss.executeForm(*b);

	delete b;
	std::cout << std::endl;

	Bureaucrat bzss("bzss", 20);
	Form	*c = inte.makeForm("presidential pardon", "coucou");

	bzss.executeForm(*c);

	boss.executeForm(*c);
	bzss.signForm(*c);
	boss.executeForm(*c);

	delete c;

	std::cout << std::endl;
	Form	*d = inte.makeForm("Inva", "Tar");
	(void) d;

}