#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack<T>() {}
		MutantStack<T>( MutantStack const & src ) {this->c = src.c;}
		~MutantStack<T>() {};

		MutantStack<T> &		operator=( MutantStack const & rhs )
		{
			this->c = rhs.c;
			return (*this);
		}

		typedef typename std::deque<T>::iterator iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}
		iterator	end()
		{
			return (this->c.end());
		}
	private:

};

#endif /* ***************************************************** MUTANTSTACK_H */