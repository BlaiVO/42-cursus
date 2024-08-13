#include <iostream>
#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	blai("Blai");
	ClapTrap	cpp("cpp");

	cpp.attack("Blai");
	blai.takeDamage(3);
	blai.beRepaired(2);
	cpp.attack("Blai");
	blai.takeDamage(12);
	blai.beRepaired(10);
	cpp.beRepaired(200);
	cpp.beRepaired(8);
	cpp.attack("Blai");
}
