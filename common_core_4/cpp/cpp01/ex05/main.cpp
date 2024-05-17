#include <iostream>
#include "Harl.hpp"

int main(void) {
	Harl	harl;

	std::cout << "Debug:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "Info:" << std::endl;
	harl.complain("INFO");
	std::cout << "Warning:" << std::endl;
	harl.complain("WARNING");
	std::cout << "Error:" << std::endl;
	harl.complain("ERROR");
	std::cout << "Invalid input:" << std::endl;
	harl.complain("SOMETHING ELSE");
	return 0;
}