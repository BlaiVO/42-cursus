#include <iostream>
#include <string>
#include "Form.hpp"

Form::Form(const std::string name, const int signing_grade, const int execution_grade): \
	 _name(name), _signing_grade(signing_grade), _execution_grade(execution_grade) {
	_is_signed = false;
	if (signing_grade < 1 || execution_grade < 1)
		throw GradeTooHighException();
	if (signing_grade > 150 || execution_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : _signing_grade(copy.getSigningGrade()), _execution_grade(copy.getExecutionGrade()){
	*this = copy;
}

Form &Form::operator= (const Form &a) {
	if (this == &a)
		return *this;
	this->_is_signed = a.getIsSigned();
	return *this;
}

Form::~Form() {}

const std::string Form::getName() const {
	return (this->_name);
}

bool	Form::getIsSigned() const {
	return (this->_is_signed);
}

int	Form::getSigningGrade() const {
	return (this->_signing_grade);
}

int	Form::getExecutionGrade() const {
	return (this->_execution_grade);
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signing_grade)
		throw Form::GradeTooLowException();
	this->_is_signed = true;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
};

std::ostream	&operator<<(std::ostream &o, Form const &form) {
	o << "Form " << form.getName() << ", is signed: " << form.getIsSigned() \
		<< ", signing grade: " << form.getSigningGrade() << ", execution grade: " << form.getExecutionGrade();
	return o;
}