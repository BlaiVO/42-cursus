#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern{
	private:
	public:
		Intern(const std::string name, int grade);
		Intern(const Intern &copy);
		Intern &operator= (const Intern &a);
		~Intern();
		AForm	*makeForm(std::string name, std::string target);
};

#endif