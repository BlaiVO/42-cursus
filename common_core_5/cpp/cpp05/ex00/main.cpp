#include <Bureaucrat.hpp>
#include <stdio.h>

int main(void)
{
	Bureaucrat bur = Bureaucrat("bur", 150);
	Bureaucrat bur2 = bur;
	std::cout << bur << std::endl;
	std::cout << bur2 << std::endl;
	try
	{
		bur.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}