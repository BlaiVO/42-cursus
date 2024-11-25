#include <iostream>
#include <string>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {
	this->_target = copy.getTarget();
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &a) {
	if (this == &a)
		return *this;
	this->_target = a.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string	RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::checkExecutable(executor);
	std::cout << "*Drilling noises*" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been successfully robotomized" << std::endl;
	else
		std::cout << this->_target << "'s robotomy has failed" << std::endl;
}
