#include <iostream>
#include "Fixed.hpp"


Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
	return;
}

Fixed::Fixed(const int val){
	std::cout << "Int constructor called" << std::endl;
	this->value = val << this->f_bits;
	return;
}

Fixed::Fixed(const float val){
	std::cout << "Float constructor called" << std::endl;
	this->value = val * (1 << this->f_bits);
	return;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

Fixed &Fixed::operator= (const Fixed &a) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a)
		this->value = a.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void    Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
	return;
}

float	Fixed::toFloat(void) const {
	return (this->value / (float)(1 << this->f_bits));
}

int	Fixed::toInt(void) const {
	return (this->value >> this->f_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}