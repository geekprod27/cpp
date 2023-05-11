#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template< typename T>
void	iter(T	*tab, int size, void (*f)(const T&))
{
	for(int i = 0; i < size; i++)
		(*f)(tab[i]);

}

template< typename T>
void	print(T	&elem)
{
	std::cout << elem << std::endl;
}

#endif