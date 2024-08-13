#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	{
		std::cout << "----------Constructor Tests----------" << std::endl;
		std::cout << "----Making ClapTraps----" << std::endl;
		ClapTrap	clap("Clap");
		ClapTrap	clap2(clap);
		ClapTrap	clap3 = clap;

		std::cout << "----Making ScavTraps----" << std::endl;
		ScavTrap	scav("Scav");
		ScavTrap	cool_scav("Cool Scav");

		std::cout << "----Copying ScavTraps----" << std::endl;
		ScavTrap	scav2(scav);
		ScavTrap	scav3 = cool_scav;

		std::cout << "----Destructors go brrrr----" << std::endl;
	}
	{
		std::cout << "----------Functionality Tests----------" << std::endl;
		ScavTrap scav("Scav");
		scav.guardGate();
		scav.attack("Evaluator");
		scav.takeDamage(20);
		scav.beRepaired(12);
		scav.takeDamage(100);
		scav.guardGate();
	}
}
