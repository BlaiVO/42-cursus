#include <iostream>
#include <string>
#include "AForm.hpp"

AForm::AForm(const std::string name, const int signing_grade, const int execution_grade): \
	 _name(name), _signing_grade(signing_grade), _execution_grade(execution_grade) {
	_is_signed = false;
	if (signing_grade < 1 || execution_grade < 1)
		throw GradeTooHighException();
	if (signing_grade > 150 || execution_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _signing_grade(copy.getSigningGrade()), _execution_grade(copy.getExecutionGrade()){
	*this = copy;
}

AForm &AForm::operator= (const AForm &a) {
	if (this == &a)
		return *this;
	this->_is_signed = a.getIsSigned();
	return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const {
	return (this->_name);
}

bool	AForm::getIsSigned() const {
	return (this->_is_signed);
}

int	AForm::getSigningGrade() const {
	return (this->_signing_grade);
}

int	AForm::getExecutionGrade() const {
	return (this->_execution_grade);
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signing_grade)
		throw AForm::GradeTooLowException();
	this->_is_signed = true;
}

void	AForm::checkExecutable(Bureaucrat const &executor) const {
	if (!this->_is_signed)
		throw (AForm::FormNotSignedExeption());
	if (executor.getGrade() > this->_execution_grade)
		throw (AForm::GradeTooLowException());
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
};

const char *AForm::FormNotSignedExeption::what(void) const throw()
{
	return ("form is yet to be signed");
};

std::ostream	&operator<<(std::ostream &o, AForm const &Aform) {
	o << "AForm " << Aform.getName() << ", is signed: " << Aform.getIsSigned() \
		<< ", signing grade: " << Aform.getSigningGrade() << ", execution grade: " << Aform.getExecutionGrade();
	return o;
}