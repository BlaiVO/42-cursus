#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal {
	private:
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator= (const WrongAnimal &a);
		~WrongAnimal();
		void	makeSound() const;
		std::string		getType() const;
	protected:
		std::string	type;
};

#endif
