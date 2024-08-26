#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	private:
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator= (const Brain &a);
		~Brain();
		std::string ideas[100];
};

#endif
