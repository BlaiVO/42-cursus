#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator= (const PresidentialPardonForm &a);
		~PresidentialPardonForm();
		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif