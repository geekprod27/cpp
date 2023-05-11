#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <list>
#include <stdexcept>

class NotFoundExeption : public std::exception
{
	public:
				const char* what() const throw()
				{
					return("Not found");
				}
};

template< typename T>
typename T::iterator easyfind(T	&cont, int const toFind)
{
	typename T::iterator p = std::find(cont.begin(), cont.end(), toFind);

	if(p == cont.end())
		throw NotFoundExeption();
	return (p);
}

template< typename T>
typename T::const_iterator easyfind(T	const& cont, int const toFind)
{
	typename T::const_iterator p = std::find(cont.begin(), cont.end(), toFind);

	if(p == cont.end())
		throw NotFoundExeption();
	return (p);
}

#endif