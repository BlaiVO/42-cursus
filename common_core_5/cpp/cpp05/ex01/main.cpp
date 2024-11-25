#include <Bureaucrat.hpp>
#include <stdio.h>

int main(void)
{
	{
		std::cout << "-----Creation execptions test-----" << std::endl;
		try
		{
			Form high = Form("too_high", 0, 0);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		try
		{
			Form bur = Form("too_low", 151, 151);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		Form *form = new Form("Tahiti visa", 50, 25);
		Bureaucrat *bur_high = new Bureaucrat("Dutch Van Der Line", 10);
		Bureaucrat *bur_low = new Bureaucrat("John Marston", 100);

		std::cout << std::endl <<  "-----Ostream test-----" << std::endl;
		std::cout << *form << std::endl;

		std::cout << std::endl <<  "-----Getters test-----" << std::endl;
		std::cout << "Name: " << form->getName() << std::endl;
		std::cout << "IsSigned: " << form->getIsSigned() << std::endl;
		std::cout << "SigningGrade: " << form->getSigningGrade() << std::endl;
		std::cout << "ExecutionGrade: " << form->getExecutionGrade() << std::endl;

		std::cout << std::endl <<  "-----Signing tests-----" << std::endl;
		bur_low->signForm(*form);
		std::cout << "IsSigned: " << form->getIsSigned() << std::endl;
		bur_high->signForm(*form);
		std::cout << "IsSigned: " << form->getIsSigned() << std::endl;
	}


}