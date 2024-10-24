#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	if (grade < 1 || grade > 150)
	{}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &a) {
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

const std::string Bureaucrat::get_name() {
	return (this->_name);
}

int	Bureaucrat::get_grade() {
	return (this->_grade);
}

void Bureaucrat::increment_grade() {
	if (this->_grade == 1)
	{
		throw GradeTooHighException();
	}
	(this->_grade)--;
}
void Bureaucrat::decrement_grade() {
	if (this->_grade == 150)
	{
		throw GradeTooHighException();
	}
	(this->_grade)++;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};
