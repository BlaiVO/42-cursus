#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator= (const Dog &a);
		~Dog();
		void	makeSound() const;
		void	setIdea(unsigned int index, std::string idea);
		void	printIdeas() const;
};

#endif
