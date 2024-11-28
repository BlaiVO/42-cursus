#include <iostream>
#include <string>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern &Intern::operator= (const Intern &a) {
	if (this == &a)
		return *this;
	return *this;
}

Intern::~Intern() {
}


AForm *Intern::findForm(std::string form, std::string target) {
	AForm* (Intern::*lstFuntions[3])(std::string target) = {&Intern::MakeShrubberyCreationForm, &Intern::MakeRobotomyRequestForm, &Intern::MakePresidentialPardonForm};
	std::string lstForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int i = 0;
	while (i < 3 && form.compare(lstForms[i]))
		i++;

	AForm *createdForm = NULL;
	if (i < 3)
		createdForm = (this->*lstFuntions[i])(target);
	return (createdForm);
}

AForm *Intern::MakeShrubberyCreationForm(std::string target) {
	return(new ShrubberyCreationForm(target));
}

AForm *Intern::MakeRobotomyRequestForm(std::string target) {
	return(new RobotomyRequestForm(target));
}

AForm *Intern::MakePresidentialPardonForm(std::string target) {
	return(new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target) {

	AForm *createdForm = findForm(form, target);

	if (createdForm == NULL)
		std::cerr << "Could not make form " << form << std::endl;
	else
		std::cout << "Intern creates " << form << " form" << std::endl;
	return (createdForm);
}