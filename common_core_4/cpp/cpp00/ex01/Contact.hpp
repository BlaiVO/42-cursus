#include <string>

#ifndef CONTACT_H
# define CONTACT_H

class Contact {
	private:
		std::string	_f_name;
		std::string _l_name;
		std::string _n_name;
		std::string	_phone;
		std::string	_secret;
		void	set_value(			
			std::string	f_name,
			std::string l_name,
			std::string n_name,
			std::string	phone,
			std::string	secret
		);

	public:
		Contact();
		Contact(
			std::string	f_name,
			std::string l_name,
			std::string n_name,
			std::string	phone,
			std::string	secret
		);
		~Contact(void);
};


#endif
