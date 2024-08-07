#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	std::cout << "Welcome to this very fun main :)." << std::endl;
	std::cout << "Subject tests:" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
