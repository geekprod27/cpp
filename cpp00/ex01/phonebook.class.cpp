#include <iostream>
#include "phonebook.class.hpp"

phonebook::phonebook( void ) {
	//std::cout << "Constructor called Phonebook" << std::endl;
	this->index = 0;
	return ;
}

phonebook::~phonebook( void ) {
	//std::cout << "Destructor called Phonebook" << std::endl;
	return ;
}

Contact	phonebook::getcontact(int index)
{
	return (this->contact[index]);
}

void	phonebook::setcontact(Contact contact)
{
	this->contact[index] = contact;
	this->index = (this->index + 1) % 8;
}