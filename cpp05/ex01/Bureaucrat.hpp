#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Form;

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		class GradeTooHighException : public std::exception
		{
			public:

				virtual const char * what() const throw()
				{
					return ("Bureaucrat : Grade too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char * what() const throw()
				{
					return ("Bureaucrat : Grade too low");
				}
		};

		void			upgrade();
		void			downgrade();

		void			signForm(Form &fo);

		std::string		getName() const;
		int				getGrade() const;
	private:

		int			 		_grade;
		const std::string 	_name;
};

std::ostream & operator<<(std::ostream &, Bureaucrat const & rhs);

#endif /* ****************************************************** BUREAUCRAT_H */