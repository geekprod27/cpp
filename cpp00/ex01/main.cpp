#include "phonebook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <string>

std::string	resizeaff(std::string str)
{
	if (str.length() < 10)
	{
		while (str.length() < 10)
			str.append(" ");
	}
	else if (str.length() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	return (str);
}

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
	std::cout << "  Index   |first name|last name |nickname" << std::endl;
	if (phone->getcontact(0).getfname().empty() == false)
		std::cout << "    0     |" << resizeaff(phone->getcontact(0).getfname()) << "|" << resizeaff(phone->getcontact(0).getlname()) << "|" << resizeaff(phone->getcontact(0).getnname()) << std::endl;
	if (phone->getcontact(1).getfname().empty() == false)
		std::cout << "    1     |" << resizeaff(phone->getcontact(1).getfname()) << "|" << resizeaff(phone->getcontact(1).getlname()) << "|" << resizeaff(phone->getcontact(1).getnname()) << std::endl;
	if (phone->getcontact(2).getfname().empty() == false)
		std::cout << "    2     |" << resizeaff(phone->getcontact(2).getfname()) << "|" << resizeaff(phone->getcontact(2).getlname()) << "|" << resizeaff(phone->getcontact(2).getnname()) << std::endl;
	if (phone->getcontact(3).getfname().empty() == false)
		std::cout << "    3     |" << resizeaff(phone->getcontact(3).getfname()) << "|" << resizeaff(phone->getcontact(3).getlname()) << "|" << resizeaff(phone->getcontact(3).getnname()) << std::endl;
	if (phone->getcontact(4).getfname().empty() == false)
		std::cout << "    4     |" << resizeaff(phone->getcontact(4).getfname()) << "|" << resizeaff(phone->getcontact(4).getlname()) << "|" << resizeaff(phone->getcontact(4).getnname()) << std::endl;
	if (phone->getcontact(5).getfname().empty() == false)
		std::cout << "    5     |" << resizeaff(phone->getcontact(5).getfname()) << "|" << resizeaff(phone->getcontact(5).getlname()) << "|" << resizeaff(phone->getcontact(5).getnname()) << std::endl;
	if (phone->getcontact(6).getfname().empty() == false)
		std::cout << "    6     |" << resizeaff(phone->getcontact(6).getfname()) << "|" << resizeaff(phone->getcontact(6).getlname()) << "|" << resizeaff(phone->getcontact(6).getnname()) << std::endl;
	if (phone->getcontact(7).getfname().empty() == false)
		std::cout << "    7     |" << resizeaff(phone->getcontact(7).getfname()) << "|" << resizeaff(phone->getcontact(7).getlname()) << "|" << resizeaff(phone->getcontact(7).getnname()) << std::endl;
	std::cout << "Index du contact a affiche : ";
	std::cin >> index;
	std::cin.ignore();
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
		getline(std::cin, cmd);
		if (std::cin.eof())
			break ;
		if (cmd.compare("ADD") == 0)
			add(&phone);
		else if (cmd.compare("SEARCH") == 0)
			search(&phone);
		else if (cmd.compare("EXIT") == 0)
			break ;
	}
	return (0);
}