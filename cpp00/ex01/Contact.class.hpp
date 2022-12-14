#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

class Contact {

public:

	Contact(void);
	~Contact(void);
	void			setfname(std::string	name);
	std::string		getfname(void);
	void			setlname(std::string	name);
	std::string		getlname(void);
	void			setnname(std::string	name);
	std::string		getnname(void);
	void			setnphone(std::string	name);
	std::string		getnphone(void);
	void			setsecret(std::string	name);
	std::string		getsecret(void);

private:

	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	nphone;
	std::string	secret;
};

#endif