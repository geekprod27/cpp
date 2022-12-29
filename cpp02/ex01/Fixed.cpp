#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->nb = 0;
}

Fixed::Fixed( int const n )
{
	std::cout << "Int constructor called" << std::endl;
	this->nb = n << this->nbits;
}

Fixed::Fixed( float const n )
{
	std::cout << "Float constructor called" << std::endl;
	this->nb = (int)roundf(n * (1 << this->nbits));
}

Fixed::Fixed( Fixed	const &cp )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	return (this->nb);
}

void	Fixed::setRawBits( int const raw )
{
	this->nb = raw;
}

float 	Fixed::toFloat( void ) const
{
	return ((float) this->nb / (float) (1 << this->nbits));
}

int 	Fixed::toInt( void ) const
{
	return (this->nb >> this->nbits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->nb = rhs.getRawBits();
	}
	return (*this);
}