#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &a) {
	if (this == &a)
		return *this;

	this->_grade = a.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

const std::string Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
	{
		throw GradeTooHighException();
	}
	(this->_grade)--;
}
void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
	{
		throw GradeTooLowException();
	}
	(this->_grade)++;
}

void	Bureaucrat::signForm(Form form)
{
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat) {
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return o;
}