#include <iostream>
#include "Fixed.hpp"

int main   (void) {
	std::cout << "Subject tests" << std::endl;
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << "setRawBits tests (destructors for subject tests will appear later)" << std::endl;
	a.setRawBits(4);
	b.setRawBits(5);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << "Calling c = a" << std::endl;
	c = a;
	std::cout << c.getRawBits() << std::endl;
	std::cout << "Calling Fixed d(b)" << std::endl;
	Fixed d(b);
	std::cout << d.getRawBits() << std::endl;

	return 0;
}