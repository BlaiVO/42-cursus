#include <string>

#ifndef CONTACT_H
# define CONTACT_H

class Contact {
	public:
		std::string	f_name; 
		std::string l_name;
		std::string n_name;
		std::string	phone;
		std::string	secret;
		int			is_set;
		Contact();
		~Contact(void);
};

#endif
