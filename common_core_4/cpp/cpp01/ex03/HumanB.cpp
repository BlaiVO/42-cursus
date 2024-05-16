#include <string>
#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string new_name) {
	name = new_name;
	weapon = NULL;
	return;
}

HumanB::~HumanB(void) {
	return;
}

void	HumanB::setWeapon(Weapon &new_weapon){
	weapon = &new_weapon;
}

void	HumanB::attack(void) {
	std::cout << name << " attacks";
	if (weapon != NULL)
		std::cout << " with their " << weapon->getType();
	std::cout << std::endl;
}