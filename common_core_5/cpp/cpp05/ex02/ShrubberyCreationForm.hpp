#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class ShrubberryCreationForm : public AForm{
	private:
		std::string	_target;
	public:
		ShrubberryCreationForm(const std::string target);
		ShrubberryCreationForm(const ShrubberryCreationForm &copy);
		ShrubberryCreationForm &operator= (const ShrubberryCreationForm &a);
		~ShrubberryCreationForm();
		std::string	getTarget() const;
};

#endif