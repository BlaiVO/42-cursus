#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	public:
		FragTrap(std::string new_name);
		FragTrap(const FragTrap &copy);
		FragTrap &operator= (const FragTrap &a);
		~FragTrap(void);
		void highFivesGuys();
};

#endif
