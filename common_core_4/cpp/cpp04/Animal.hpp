#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	private:
	public:
		Animal();
		Animal(const Animal &copy);
		Animal &operator= (const Animal &a);
		~Animal();
	protected:
		std::string	type;
};

#endif
