#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_signing_grade;
		const int			_execution_grade;
	public:
		Form(const std::string name, const int signing_grade, const int execution_grade);
		Form(const Form &copy);
		Form &operator= (const Form &a);
		~Form();
		const std::string	getName() const;
		bool				getIsSigned() const;
		const int			getSigningGrade() const;
		const int			getExecutionGrade() const;
		void				beSigned(Bureaucrat bureaucrat);

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

std::ostream	&operator<<(std::ostream &o, Form const &Form);

#endif