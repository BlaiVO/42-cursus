#include "Weapon.hpp"

Weapon::Weapon() {
	return;
}

Weapon::Weapon(std::string new_type) {
	type = new_type;
	return;
}

Weapon::~Weapon() {
	return;
}

const std::string	&Weapon::getType(void) {
	const std::string &typeREF = type;
	return (typeREF);
}

void	Weapon::setType(std::string new_type) {
	type = new_type;
}