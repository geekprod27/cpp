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

	bool operator>(Fixed const & rhs) const;
	bool operator<(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;

	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;


	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	Fixed static	max(Fixed const & un, Fixed const & deux);
	Fixed static	min(Fixed const & un, Fixed const & deux);

	Fixed static	max(Fixed & un, Fixed & deux);
	Fixed static	min(Fixed & un, Fixed & deux);

private:

	int					nb;
	static const int 	nbits = 8;
};

std::ostream & operator<<(std::ostream &, Fixed const & rhs);

#endif