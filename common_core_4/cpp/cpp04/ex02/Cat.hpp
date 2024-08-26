#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain	*brain;
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator= (const Cat &a);
		~Cat();
		void	makeSound() const;
		void	setIdea(unsigned int index, std::string idea);
		void	printIdeas() const;
};

#endif
