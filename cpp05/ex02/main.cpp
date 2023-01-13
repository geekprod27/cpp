#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat boss("boss", 1);
	
	
	Bureaucrat buss("buss", 144);
	ShrubberyCreationForm	a("jardin");

	buss.executeForm(a);

	boss.executeForm(a);
	buss.signForm(a);
	boss.executeForm(a);

	std::cout << std::endl;

	Bureaucrat bass("bass", 72);
	RobotomyRequestForm	b("llaalalal");

	bass.executeForm(b);

	boss.executeForm(b);
	bass.signForm(b);
	boss.executeForm(b);


	std::cout << std::endl;

	Bureaucrat bzss("bzss", 20);
	PresidentialPardonForm	c("cou");

	bzss.executeForm(c);

	boss.executeForm(c);
	bzss.signForm(c);
	boss.executeForm(c);
}