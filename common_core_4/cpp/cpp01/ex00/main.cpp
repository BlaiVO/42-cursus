#include <iostream>
#include "Zombie.hpp"
#include "newZombie.cpp"
#include "randomChump.cpp"

int main(void)
{
	std::cout << "Creating and announcing heap allocated zombie" << std::endl;
	Zombie	*heapZombie = newZombie("Sophie");
	heapZombie->announce();
	std::cout << "Calling randomChump()" << std::endl;
	randomChump("Allan");
	std::cout << "Deleting heap allocated zombie" << std::endl;
	delete heapZombie;
	return (0);
}