#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	{
		std::cout << "--------------Subject Tests--------------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		//* Subject does not delete the animals, I will do it to prevent leaks
		delete(meta);
		delete(j);
		delete(i);
	}
	{
		std::cout << "--------------Animal Tests--------------" << std::endl;
		Animal a;
		Animal b(a);
		Animal c = b;

		std::cout << a.getType() << std::endl;

		a.makeSound();
		b.makeSound();
		c.makeSound();
	}
	{
		std::cout << "--------------Dog Tests--------------" << std::endl;
		Dog a;
		Dog b(a);
		Dog c = b;

		std::cout << a.getType() << std::endl;

		a.makeSound();
		b.makeSound();
		c.makeSound();
	}
	{
		std::cout << "--------------Cat Tests--------------" << std::endl;
		Cat a;
		Cat b(a);
		Cat c = b;

		std::cout << a.getType() << std::endl;

		a.makeSound();
		b.makeSound();
		c.makeSound();
	}
	{
		std::cout << "--------------Wrong Animal Tests--------------" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();
		//* Subject does not delete the animals, I will do it to prevent leaks
		delete(meta);
		delete(i);
	}
}
