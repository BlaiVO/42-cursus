#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_signing_grade;
		const int			_execution_grade;
	public:
		AForm(const std::string name, const int signing_grade, const int execution_grade);
		AForm(const AForm &copy);
		AForm &operator= (const AForm &a);
		virtual ~AForm();
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSigningGrade() const;
		int					getExecutionGrade() const;
		void				beSigned(Bureaucrat &bureaucrat);
		virtual	void		execute(Bureaucrat const & executor) const = 0;

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

	class FormNotSigned : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm const &AForm);

#endif