#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
#include "Form.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		Form	*makeForm(std::string name, std::string target);

	private:

};

#endif /* ********************************************************** INTERN_H */