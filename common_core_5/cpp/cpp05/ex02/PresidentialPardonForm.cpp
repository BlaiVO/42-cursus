#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {
	this->_target = copy.getTarget();
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &a) {
	if (this == &a)
		return *this;
	this->_target = a.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string	PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::checkExecutable(executor);
	std::cout << this->_target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
