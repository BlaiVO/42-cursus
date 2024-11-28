#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern{
	private:
		AForm	*findForm(std::string form, std::string target);
		AForm	*MakeShrubberyCreationForm(std::string target);
		AForm	*MakeRobotomyRequestForm(std::string target);
		AForm	*MakePresidentialPardonForm(std::string target);
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator= (const Intern &a);
		~Intern();
		AForm	*makeForm(std::string name, std::string target);
};

#endif