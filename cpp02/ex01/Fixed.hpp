#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

public:

	Fixed( void );
	Fixed( int const n );
	Fixed( float const n );
	Fixed( Fixed const &cp );
	~Fixed( void );

	float 	toFloat( void ) const;
	int 	toInt( void ) const;
	int 	getRawBits( void ) const;
	void	setRawBits( int const raw );

	Fixed & operator=(Fixed const & rhs);

private:

	int					nb;
	static const int 	nbits = 8;
};

std::ostream & operator<<(std::ostream &, Fixed const & rhs);

#endif