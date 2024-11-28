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
	Bureaucrat	new_guy = Bureaucrat("New Guy", 150);

	std::cout << "-----Shrubbery Tests-----" << std::endl;
	new_guy.signForm(shrubbery);
	president.executeForm(shrubbery);
	president.signForm(shrubbery);
	new_guy.executeForm(shrubbery);
	president.executeForm(shrubbery);

	std::cout << std::endl << "-----Robotomy Tests-----" << std::endl;
	new_guy.signForm(robotomy);
	president.executeForm(robotomy);
	president.signForm(robotomy);
	new_guy.executeForm(robotomy);
	president.executeForm(robotomy);

	std::cout << std::endl << "-----Presidential Pardon Tests-----" << std::endl;
	new_guy.signForm(pardon);
	president.executeForm(pardon);
	president.signForm(pardon);
	new_guy.executeForm(pardon);
	president.executeForm(pardon);
}