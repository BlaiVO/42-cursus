#include <string>
#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB {
	private:
		std::string	name;
		Weapon *weapon;
	public:
		HumanB(std::string new_name);
		~HumanB();
		void	setWeapon(Weapon &new_weapon);
		void	attack(void);
};

#endif