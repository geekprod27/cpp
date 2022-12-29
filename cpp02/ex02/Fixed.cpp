#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed( void )
{
	this->nb = 0;
}

Fixed::Fixed( int const n )
{
	this->nb = n << this->nbits;
}

Fixed::Fixed( float const n )
{
	this->nb = (int)roundf(n * (1 << this->nbits));
}

Fixed::Fixed( Fixed	const &cp )
{
	*this = cp;
}

Fixed::~Fixed( void )
{
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

// Operateur coparaison

bool Fixed::operator>( Fixed const & rhs ) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<( Fixed const & rhs ) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=( Fixed const & rhs ) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=( Fixed const & rhs ) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==( Fixed const & rhs ) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=( Fixed const & rhs ) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

//Operateur arithmetique

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() - rhs.getRawBits());
	return ret;
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() * rhs.getRawBits() >> this->nbits);
	return ret;
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	Fixed	ret;

	if (rhs.toFloat() != 0)
		ret.setRawBits((this->getRawBits() * ( 1 << this->nbits)) / rhs.getRawBits());
	else
		std::cerr << "Division par 0 impossible" << std::endl;
	return ret;
}

// Operateur d'incrementation

Fixed &Fixed::operator++( void )
{
	this->nb++;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed tmp(*this);
	++*this;
	return (tmp);
}

Fixed &Fixed::operator--( void )
{
	this->nb--;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	--*this;
	return (tmp);
}

// min max

Fixed	Fixed::max(Fixed const & un, Fixed const & deux)
{
	if (un > deux)
		return (un);
	else
		return (deux);
}

Fixed	Fixed::min(Fixed const & un, Fixed const & deux)
{
	if (un < deux)
		return (un);
	else
		return (deux);
}

Fixed	Fixed::max(Fixed & un, Fixed & deux)
{
	if (un > deux)
		return (un);
	else
		return (deux);
}

Fixed	Fixed::min(Fixed & un, Fixed & deux)
{
	if (un < deux)
		return (un);
	else
		return (deux);
}