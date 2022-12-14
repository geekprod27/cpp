#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class phonebook {

public:

	phonebook(void);
	~phonebook(void);
	Contact	getcontact(int index);
	void	setcontact(Contact contact);

private:
	int		index;
	Contact	contact[8];
};

#endif