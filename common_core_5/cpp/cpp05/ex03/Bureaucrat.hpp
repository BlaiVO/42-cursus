#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator= (const Bureaucrat &a);
		~Bureaucrat();
		const std::string getName() const;
		int	getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif