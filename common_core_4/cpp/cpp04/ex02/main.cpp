#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	//Animal animal; <-- uncomment to see compiler error
	Cat	*cat = new Cat();
	Dog	dog;

	std::cout << cat->getType() << std::endl;
	std::cout << dog.getType() << std::endl;

	cat->makeSound();
	dog.makeSound();

	delete cat;

}
