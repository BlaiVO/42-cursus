#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdio.h>

int main(void)
{
	Bureaucrat bur = Bureaucrat("test", 1);
	ShrubberyCreationForm form = ShrubberyCreationForm("test");

	bur.signForm(form);
	form.execute(bur);
}