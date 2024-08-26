#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
 {
	{
		std::cout << "--------------Subject Tests--------------" << std::endl;
		const int animal_num = 10;
		Animal *animals[animal_num];

		for (int i = 0; i < animal_num; i++) {
			if (i < animal_num / 2) {
				animals[i] = new Dog();
			} else {
				animals[i] = new Cat();
			}
		}

		std::cout << std::endl;
		std::cout << "Making animal sounds:" << std::endl;

		animals[0]->makeSound();
		animals[animal_num - 1]->makeSound();

		std::cout << std::endl;

		for (int i = 0; i < animal_num; i++) {
			delete animals[i];
		}
	}
	{
		std::cout << "--------------Deep Copy Test--------------" << std::endl;
		Cat cat = Cat();
		cat.setIdea(0, "Life in plastic is fantastic");
		Cat lucy = cat;
		std::cout << std::endl;

		cat.printIdeas();
		lucy.printIdeas();

		std::cout << std::endl;
		std::cout << "Changing original cat idea" << std::endl;
		cat.setIdea(0, "I am become God, the destroyer of worlds");
		std::cout << std::endl;

		cat.printIdeas();
		lucy.printIdeas();
		std::cout << std::endl;
	}
 }
}
