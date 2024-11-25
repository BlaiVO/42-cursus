#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator= (const RobotomyRequestForm &a);
		~RobotomyRequestForm();
		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif