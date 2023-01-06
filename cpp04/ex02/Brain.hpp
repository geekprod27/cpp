#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );

		void		setIdeas(std::string ide, int id);
		std::string	getIdeas(int id);

	private:
		std::string	ideas[100];
};

#endif /* *********************************************************** BRAIN_H */