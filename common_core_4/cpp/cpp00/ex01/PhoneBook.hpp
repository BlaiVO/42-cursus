#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"

class PhoneBook {
	private:
		int total_contacts;
		void	printValue(std::string value);
		void	printContact(Contact contact);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
		Contact contacts[8];
};

#endif
