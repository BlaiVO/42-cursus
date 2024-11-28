#include <iostream>
#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
	this->_target = copy.getTarget();
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &a) {
	if (this == &a)
		return *this;
	this->_target = a.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string	ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::checkExecutable(executor);
	std::string	filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	file <<
		"             .o00o\n"
        "           o000000oo\n"
        "          00000000000o\n"
        "         00000000000000\n"
        "      oooooo  00000000  o88o\n"
        "   ooOOOOOOOoo  ```''  888888\n"
        " OOOOOOOOOOOO'.qQQQQq. `8888'\n"
        "oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
        "OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
        " OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
        "   OOOOOOOOO `QQQQQQ/ /QQ'\n"
        "     OO:F_P:O `QQQ/  /Q'\n"
        "       \\\\. \\ |  // |\n"
        "        d\\ \\\\\\|_////\n"
        "        qP| \\\\ _' `|Ob\n"
        "           \\  / \\  \\Op\n"
        "           |  | O| |\n"
        "   _       /\\\\. \\_/ /\\\n"
        "    `---__/|_\\\\   //|  __\n"
        "          `-'  `-'`-'-'\n";
	file.close();
}
