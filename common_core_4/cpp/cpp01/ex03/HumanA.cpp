#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string new_name, Weapon &new_weapon) : weapon(new_weapon) {
	name = new_name;
	return;
}

HumanA::~HumanA(void) {
	return;
}

void	HumanA::attack(void) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}