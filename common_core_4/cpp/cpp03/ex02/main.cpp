#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

		std::cout << "----Making FragTraps----" << std::endl;
		FragTrap	frag("Frag");
		FragTrap	cool_frag("Cool Frag");

		std::cout << "----Copying FragTraps----" << std::endl;
		FragTrap	frag2(frag);
		FragTrap	frag3 = cool_frag;

		std::cout << "----Destructors go brrrr----" << std::endl;
	}
	{
		std::cout << "----------Functionality Tests----------" << std::endl;
		FragTrap frag("Frag");
		frag.highFivesGuys();
		frag.attack("Evaluator");
		frag.takeDamage(20);
		frag.beRepaired(12);
		frag.takeDamage(100);
		frag.highFivesGuys();
	}
}
