#include "phonebook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void	affcontact(Contact contact)
{
	if (contact.getfname().empty())
	{
		std::cout << "Non enregiste !" << std::endl;
		return ;
	}
	std::cout << "First name : " << contact.getfname() << std::endl;
	std::cout << "Last name : " << contact.getlname() << std::endl;
	std::cout << "Nick name : " << contact.getnname() << std::endl;
	std::cout << "Phone numbers : " << contact.getnphone() << std::endl;
	std::cout << "Darkest secret : " << contact.getsecret() << std::endl;
}

void	search(phonebook *phone)
{
	int	index;

	std::cout << "Contact enregistre" << std::endl;
	std::cout << "  Index   |first name| last name|nickname" << std::endl;
	if (phone->getcontact(0).getfname().empty() == false)
		std::cout << "    0     |" << std::setw(10) << phone->getcontact(0).getfname() << "|" << std::setw(10) << phone->getcontact(0).getlname() << "|" << std::setw(10) << phone->getcontact(0).getnname() << std::endl;
	if (phone->getcontact(1).getfname().empty() == false)
		std::cout << "    1     |" << std::setw(10) << phone->getcontact(1).getfname() << "|" << std::setw(10) << phone->getcontact(1).getlname() << "|" << std::setw(10) << phone->getcontact(1).getnname() << std::endl;
	if (phone->getcontact(2).getfname().empty() == false)
		std::cout << "    2     |" << std::setw(10) << phone->getcontact(2).getfname() << "|" << std::setw(10) << phone->getcontact(2).getlname() << "|" << std::setw(10) << phone->getcontact(2).getnname() << std::endl;
	if (phone->getcontact(3).getfname().empty() == false)
		std::cout << "    3     |" << std::setw(10) << phone->getcontact(3).getfname() << "|" << std::setw(10) << phone->getcontact(3).getlname() << "|" << std::setw(10) << phone->getcontact(3).getnname() << std::endl;
	if (phone->getcontact(4).getfname().empty() == false)
		std::cout << "    4     |" << std::setw(10) << phone->getcontact(4).getfname() << "|" << std::setw(10) << phone->getcontact(4).getlname() << "|" << std::setw(10) << phone->getcontact(4).getnname() << std::endl;
	if (phone->getcontact(5).getfname().empty() == false)
		std::cout << "    5     |" << std::setw(10) << phone->getcontact(5).getfname() << "|" << std::setw(10) << phone->getcontact(5).getlname() << "|" << std::setw(10) << phone->getcontact(5).getnname() << std::endl;
	if (phone->getcontact(6).getfname().empty() == false)
		std::cout << "    6     |" << std::setw(10) << phone->getcontact(6).getfname() << "|" << std::setw(10) << phone->getcontact(6).getlname() << "|" << std::setw(10) << phone->getcontact(6).getnname() << std::endl;
	if (phone->getcontact(7).getfname().empty() == false)
		std::cout << "    7     |" << std::setw(10) << phone->getcontact(7).getfname() << "|" << std::setw(10) << phone->getcontact(7).getlname() << "|" << std::setw(10) << phone->getcontact(7).getnname() << std::endl;
	std::cout << "Index du contact a affiche : ";
	std::cin >> index;
	std::cin.ignore();
	if (!std::cin.good())
	{
		std::cout << "Erreur !" << std::endl;
		return ;
	}
	if (index < 0 || index > 7)
	{
		std::cout << "Index inconu" << std::endl;
		return ;
	}
	affcontact(phone->getcontact(index));

}

void	add(phonebook *phone)
{
	Contact			contact;
	std::string		tmp;

	tmp = "";
	while (tmp.empty() != 0)
	{
		std::cout << "Enter first name : ";
		getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
	}
	contact.setfname(tmp);
	tmp.clear();
	while (tmp.empty() != 0)
	{
		std::cout << "Enter last name : ";
		getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
	}
	contact.setlname(tmp);
	tmp.clear();
	while (tmp.empty() != 0)
	{
		std::cout << "Enter nickname : ";
		getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
	}
	contact.setnname(tmp);
	tmp.clear();
	while (tmp.empty() != 0)
	{
		std::cout << "Enter Phone number : ";
		getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
	}
	contact.setnphone(tmp);
	tmp.clear();
	while (tmp.empty() != 0)
	{
		std::cout << "Enter darkest secret : ";
		getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
	}
	contact.setsecret(tmp);
	phone->setcontact(contact);
}

int main() {
	phonebook	phone;
	std::string	cmd;

	while(42) {
		std::cout << "PhoneBook : ";
		std::cin.clear();
		getline(std::cin, cmd);
		if (std::cin.eof())
			break ;
		if (cmd.compare("ADD") == 0)
			add(&phone);
		else if (cmd.compare("SEARCH") == 0)
			search(&phone);
		else if (cmd.compare("EXIT") == 0)
			break ;
		std::cin.clear();
		std::cin.ignore();
	}
	return (0);
}