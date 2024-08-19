#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap(std::string new_name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator= (const ScavTrap &a);
		~ScavTrap(void);
		void	attack(const std::string &target);
		void	guardGate();
};

#endif
