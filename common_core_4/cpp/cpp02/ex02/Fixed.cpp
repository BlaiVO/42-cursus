#include <iostream>
#include "Fixed.hpp"


Fixed::Fixed(){
	//std::cout << "Default constructor called" << std::endl;
	this->value = 0;
	return;
}

Fixed::Fixed(const int val){
	//std::cout << "Int constructor called" << std::endl;
	this->value = val << this->f_bits;
	return;
}

Fixed::Fixed(const float val){
	//std::cout << "Float constructor called" << std::endl;
	this->value = val * (1 << this->f_bits);
	return;
}

Fixed::Fixed(const Fixed &copy){
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator= (const Fixed &a) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a)
		this->value = a.getRawBits();
	return *this;
}

int Fixed::operator> (const Fixed &a) {
	return this->value > a.getRawBits();
}

int Fixed::operator< (const Fixed &a) {
	return this->value < a.getRawBits();
}

int Fixed::operator>= (const Fixed &a) {
	return this->value >= a.getRawBits();
}

int Fixed::operator<= (const Fixed &a) {
	return this->value <= a.getRawBits();
}

int Fixed::operator== (const Fixed &a) {
	return this->value == a.getRawBits();
}

int Fixed::operator!= (const Fixed &a) {
	return this->value != a.getRawBits();
}

Fixed Fixed::operator+ (const Fixed &a) {
	return Fixed(this->toFloat() + a.toFloat());
}

Fixed Fixed::operator- (const Fixed &a) {
	return Fixed(this->toFloat() - a.toFloat());
}

Fixed Fixed::operator* (const Fixed &a) {
	return Fixed(this->toFloat() * a.toFloat());
}

Fixed Fixed::operator/ (const Fixed &a) {
	return Fixed(this->toFloat() / a.toFloat());
}

Fixed &Fixed::operator++() {
	*this = *this + Fixed(1);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed	tmp = *this;
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--() {
	*this = *this - Fixed(1);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	tmp = *this;
	--(*this);
	return tmp;
}

int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void    Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
	return;
}

float	Fixed::toFloat(void) const {
	return (this->value / (float)(1 << this->f_bits));
}

int	Fixed::toInt(void) const {
	return (this->value >> this->f_bits);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 <= f2)
		return (f1);
	return f2;
}
const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return f2;
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 >= f2)
		return (f1);
	return f2;
}
const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return f2;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}