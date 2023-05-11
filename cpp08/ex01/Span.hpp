#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{

	public:

		Span(unsigned int cap);
		Span( Span const & src );
		~Span();

		void addNumber(int num);
		long shortestSpan();
		long longestSpan();

		Span &		operator=( Span const & rhs );

		void	fill(std::vector<int>::iterator start, std::vector<int>::iterator stop);

	private:

		Span();

		std::vector<int>	_list;
		unsigned int 		_capa;
};

class FullSpanExeption : public std::exception
{
	public:
				const char* what() const throw()
				{
					return("Span full");
				}
};

class DistImpExeption : public std::exception
{
	public:
				const char* what() const throw()
				{
					return("Impossible de calculer la distance");
				}
};


#endif /* ************************************************************ SPAN_H */