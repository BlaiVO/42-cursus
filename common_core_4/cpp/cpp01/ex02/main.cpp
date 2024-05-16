#include <string>
#include <iostream>

int main(void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string &stringRFR = brain;

	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringRFR << std::endl;

	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringRFR << std::endl;
	return (0);
}