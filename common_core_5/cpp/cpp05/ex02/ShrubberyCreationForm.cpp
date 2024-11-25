#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"

ShrubberryCreationForm::ShrubberryCreationForm(const std::string target) : AForm("ShrubberryCreationForm", 154, 137) {
	this->_target = target;
}

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm &copy) : AForm(copy) {
	this->_target = copy.getTarget();
	*this = copy;
}

ShrubberryCreationForm &ShrubberryCreationForm::operator= (const ShrubberryCreationForm &a) {
	if (this == &a)
		return *this;
	this->_target = a.getTarget();
	return *this;
}

ShrubberryCreationForm::~ShrubberryCreationForm() {}

std::string	ShrubberryCreationForm::getTarget() const {
	return this->_target;
}