#include <iostream>
#include "Zombie.hpp"
#include "zombieHorde.cpp"

int	main(void) {
	Zombie	*anthonies = zombieHorde(10, "Anthony");
	for (int i = 0; i < 10; i++) {
		std::cout << i + 1 << ". ";
		anthonies[i].announce();
	}
	delete[] anthonies;
	Zombie	*tiffanies = zombieHorde(15, "Tiffany");
	for (int i = 0; i < 15; i++) {
		std::cout << i + 1 << ". ";
		tiffanies[i].announce();
	}
	delete[] tiffanies;
}
