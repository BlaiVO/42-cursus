#include <string>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string new_name);
		~Zombie(void);
		void	announce(void);
};

#endif