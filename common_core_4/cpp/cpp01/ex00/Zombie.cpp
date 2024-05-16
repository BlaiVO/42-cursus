#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) {
	return;
}

Zombie::Zombie(std::string new_name) {
	name = new_name;
	return;
}

Zombie::~Zombie(void) {
	std::cout << name << " has been destroyed." << std::endl;
	return; 
}
void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
