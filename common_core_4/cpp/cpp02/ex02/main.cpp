#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	std::cout << "Welcome to this very fun main :)." << std::endl;
	std::cout << "This main will be way more readable if you comment the constructor/destructor couts." << std::endl;
	std::cout << std::endl;

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

	std::cout << std::endl;
	std::cout << "a, b: " << a << ", " << b << std::endl;
	std::cout << std::endl;

	std::cout << "Comparison tests:" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << std::endl;

	std::cout << "Arithmetic tests:" << std::endl ;
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "100 / b: " << (Fixed(100) / b) << std::endl;

	std::cout << std::endl;

	std::cout << "min/max tests:" << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, 4): " << Fixed::max(a, Fixed(4)) << std::endl;
	std::cout << "min(a, 4): " << Fixed::min(a, Fixed(4)) << std::endl;


	return 0;
}
