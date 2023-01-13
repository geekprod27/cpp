#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{

	public:

		Form();
		Form(std::string	name, int gradesign, int gradeexec);
		Form( Form const & src );
		virtual ~Form();

		Form &		operator=( Form const & rhs );

		std::string		getName() const;
		bool			getSign() const;
		int				getGradeSign() const;
		int				getGradeExec() const;

		void			beSigned(Bureaucrat &bu);

		virtual void	execute(Bureaucrat const & executor) const  = 0;

		class GradeTooHighException : public std::exception
		{
			public:

				virtual const char * what() const throw()
				{
					return ("Form : Grade too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char * what() const throw()
				{
					return ("Form : Grade too low");
				}
		};
		class NotSignedException : public std::exception
		{
			public:

				virtual const char * what() const throw()
				{
					return ("Form : not signed");
				}
		};

	private:

		std::string const		_name;
		bool					_sign;
		int	const				_gradesign;
		int	const				_gradeexec;
};

std::ostream & operator<<(std::ostream &, Form const & rhs);

#endif /* ************************************************************ FORM_H */