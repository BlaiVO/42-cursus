#include <string>

#ifndef CONTACT_H
# define CONTACT_H

class Contact {
	private:
		std::string	f_name; 
		std::string l_name;
		std::string n_name;
		std::string	phone;
		std::string	secret;
		int			index;
	public:
		Contact();
		~Contact(void);
		void		set_f_name(std::string new_value); 
		void		set_l_name(std::string new_value);
		void		set_n_name(std::string new_value);
		void		set_phone(std::string new_value);
		void		set_secret(std::string new_value);
		void		set_index(int new_vaue);
		std::string	get_f_nam	e(void); 
		std::string	get_l_name(void);
		std::string	get_n_name(void);
		std::string	get_phone(void);
		std::string	get_secret(void);
		int			get_index(void);
};

#endif
