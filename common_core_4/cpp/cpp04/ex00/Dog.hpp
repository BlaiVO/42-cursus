#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal{
	private:
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator= (const Dog &a);
		~Dog();
		void	makeSound()const;
};

#endif
