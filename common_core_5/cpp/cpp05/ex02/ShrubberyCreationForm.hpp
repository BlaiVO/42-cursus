#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator= (const ShrubberyCreationForm &a);
		~ShrubberyCreationForm();
		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif