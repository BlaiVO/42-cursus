#include "Intern.hpp"
#include <stdio.h>

int main(void)
{
	{
		std::cout << std::endl << "----------Shruberry test----------" << std::endl;
		Intern	intern;
		AForm*	form = intern.makeForm("shrubbery creation", "tree");

		Bureaucrat bur = Bureaucrat("bur", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	}
	{
		std::cout << std::endl << "----------Robotomy test----------" << std::endl;
		Intern	intern;
		AForm*	form = intern.makeForm("robotomy request", "robot");

		Bureaucrat bur = Bureaucrat("bur", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	}
	{
		std::cout << std::endl << "----------Presidential test----------" << std::endl;
		Intern	intern;
		AForm*	form = intern.makeForm("presidential pardon", "not that innocent dude");

		Bureaucrat bur = Bureaucrat("bur", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	}
	{
		std::cout << std::endl << "----------Unexistent test----------" << std::endl;
		Intern	intern;
		AForm*	form = intern.makeForm("unexistent form", "target");

		if (form == NULL)
			return 1; // remove this to see a beautiful segfault
		Bureaucrat bur = Bureaucrat("bur", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	}
}