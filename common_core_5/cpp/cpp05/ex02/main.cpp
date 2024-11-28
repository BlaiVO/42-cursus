#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdio.h>

int main(void)
{
	ShrubberyCreationForm	shrubbery = ShrubberyCreationForm("garden");
	RobotomyRequestForm		robotomy = RobotomyRequestForm("robot");
	PresidentialPardonForm	pardon = PresidentialPardonForm("Totally Innocent Dude");

	Bureaucrat	president = Bureaucrat("President", 1);
	Bureaucrat	intern = Bureaucrat("Intern", 150);

	std::cout << "-----Shrubbery Tests-----" << std::endl;
	intern.signForm(shrubbery);
	president.executeForm(shrubbery);
	president.signForm(shrubbery);
	intern.executeForm(shrubbery);
	president.executeForm(shrubbery);

	std::cout << std::endl << "-----Robotomy Tests-----" << std::endl;
	intern.signForm(robotomy);
	president.executeForm(robotomy);
	president.signForm(robotomy);
	intern.executeForm(robotomy);
	president.executeForm(robotomy);

	std::cout << std::endl << "-----Presidential Pardon Tests-----" << std::endl;
	intern.signForm(pardon);
	president.executeForm(pardon);
	president.signForm(pardon);
	intern.executeForm(pardon);
	president.executeForm(pardon);
}