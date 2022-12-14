#include <iostream>
#include "Contact.class.hpp"

Contact::Contact( void ) {
	//std::cout << "Constructor called Contact" << std::endl;
	return ;
}

Contact::~Contact( void ) {
	//std::cout << "Destructor called Contact" << std::endl;
	return ;
}

void	Contact::setfname(std::string	name)
{
	this->fname = name;
	return ;
}
	
std::string	Contact::getfname(void)
{
	return (this->fname);
}

void	Contact::setlname(std::string	name)
{
	this->lname = name;
	return ;
}
	
std::string	Contact::getlname(void)
{
	return (this->lname);
}

void	Contact::setnname(std::string	name)
{
	this->nname = name;
	return ;
}
	
std::string	Contact::getnname(void)
{
	return (this->nname);
}

void	Contact::setnphone(std::string	name)
{
	this->nphone = name;
	return ;
}
	
std::string	Contact::getnphone(void)
{
	return (this->nphone);
}

void	Contact::setsecret(std::string	name)
{
	this->secret = name;
	return ;
}
	
std::string	Contact::getsecret(void)
{
	return (this->secret);
}