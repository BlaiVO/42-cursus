#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"

class PhoneBook {
	private:
		int total_contacts;
		Contact contacts[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add();
		void	search(void);
};

#endif
