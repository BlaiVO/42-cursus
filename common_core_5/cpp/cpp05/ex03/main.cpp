#include "Intern.hpp"
#include <stdio.h>

int main(void)
{
	{
		Intern	intern;
		AForm*	form = intern.makeForm("shrubbery creation", "tree");

		Bureaucrat bur = Bureaucrat("bur", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	}
	{
		Intern	intern;
		AForm*	form = intern.makeForm("robotomy request", "robot");

		Bureaucrat bur = Bureaucrat("bur", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	}
	{
		Intern	intern;
		AForm*	form = intern.makeForm("presidential pardon", "not that innocent dude");

		Bureaucrat bur = Bureaucrat("bur", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	}
	{
		Intern	intern;
		AForm*	form = intern.makeForm("unexistent form", "target");

		Bureaucrat bur = Bureaucrat("bur", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	}
}