#include <string>
#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA {
	private:
		std::string	name;
		Weapon &weapon;
	public:
		HumanA(std::string new_name, Weapon &new_weapon);
		~HumanA();
		void	attack(void);
};

#endif