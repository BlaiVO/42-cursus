#include <Bureaucrat.hpp>
#include <stdio.h>

int main(void)
{
	{
		std::cout << "-----Creation execptions test-----" << std::endl;
		try
		{
			Bureaucrat bur = Bureaucrat("too_high", 0);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		try
		{
			Bureaucrat bur = Bureaucrat("too_low", 151);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		Bureaucrat *bur =  new Bureaucrat("Arthur Morgan", 150);
		std::cout << std::endl << "-----Ostream test-----" << std::endl;
		std::cout << *bur << std::endl;

		std::cout << std::endl << "-----GradeTooLowExecption test-----" << std::endl;
		try
		{
			bur->decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		delete bur;
	}
	{
		Bureaucrat *bur =  new Bureaucrat("Arthur Morgan", 1);

		std::cout << std::endl << "-----GradeTooHighExecption test-----" << std::endl;
		try
		{
			bur->incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << std::endl << "-----Getters test-----" << std::endl;
		std::cout << "Name: " << bur->getName() << std::endl;
		std::cout << "Grade: " << bur->getGrade() << std::endl;

		std::cout << std::endl << "-----Decrement/Increment test-----" << std::endl;
		bur->decrementGrade();
		std::cout << "Grade: " << bur->getGrade() << std::endl;
		bur->incrementGrade();
		std::cout << "Grade: " << bur->getGrade() << std::endl;
		delete bur;
	}
}