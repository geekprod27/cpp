#include "Span.hpp"
#include <climits>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(unsigned int cap) : _capa(cap)
{
}

Span::Span( const Span & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	std::vector<int>::const_iterator	i;
	if ( this != &rhs )
	{
		this->_capa = rhs._capa;
		for (i = rhs._list.begin(); i != rhs._list.end(); ++i)
			this->addNumber(*i);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber(int num)
{
	if (this->_list.size() >= this->_capa)
		throw FullSpanExeption();
	this->_list.push_back(num);
}


long Span::longestSpan()
{
	if (this->_list.size() < 2)
		throw DistImpExeption();
	return(static_cast<long>(*std::max_element(this->_list.begin(), this->_list.end())) - static_cast<long>(*std::min_element(this->_list.begin(), this->_list.end())));
}

long Span::shortestSpan()
{
	std::vector<int>	tmp = this->_list;
	long	shor = LONG_MAX;
	int buf = 0;

	if (this->_list.size() <= 1)
		throw DistImpExeption();
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator	i = tmp.begin();

	while(1)
	{
		buf = *i;
		if(++i == tmp.end())
			break ;
		if(shor > static_cast<long>(*i) - static_cast<long>(buf))
			shor = static_cast<long>(*i) - static_cast<long>(buf);
	}
	return(shor);

}

void	Span::fill(std::vector<int>::iterator start, std::vector<int>::iterator stop)
{
	for (; start != stop ; start++)
		this->addNumber(*start);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */