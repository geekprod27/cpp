#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << "a < b " <<(a < b) << std::endl;
	std::cout << "a > b "<< (a > b) << std::endl;
	std::cout << "a <= b "<< (a <= b) << std::endl;
	std::cout << "a >= b "<< (a >= b) << std::endl;
	std::cout << "a == b "<< (a == b) << std::endl;
	std::cout << "a != b "<< (a != b) << std::endl;
	

	std::cout << "a = 5 | c = 10" << std::endl;
	a = Fixed( 5 );
	Fixed c(10);

	std::cout << "a + c "<< (a + c) << std::endl;
	std::cout << "a - c "<< (a - c) << std::endl;
	std::cout << "a * c "<< (a * c) << std::endl;
	std::cout << "a / c "<< (a / c) << std::endl;

	return 0;
}