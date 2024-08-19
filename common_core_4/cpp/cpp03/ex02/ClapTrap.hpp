#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
	protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		ClapTrap(std::string new_name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator= (const ClapTrap &a);
		~ClapTrap(void);
		virtual void	attack(const std::string &target);
		void	takeDamage(unsigned int ammount);
		void	beRepaired(unsigned int ammount);
};

#endif
