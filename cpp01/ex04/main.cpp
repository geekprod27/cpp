#include <iostream>
#include <fstream>
#include <ctype.h>

void	replacefile(std::ifstream&	ifs, std::ofstream&	ofs, std::string& chr, std::string& rep)
{
	char 		c;
	std::string str;
	size_t		i = 0;
	size_t 		j;
	while (!ifs.eof())
	{
		ifs.get(c);
		if(c)
			str += c;
		i = str.find(chr, 0);
		if (i != std::string::npos)
		{
			for(j = 0; j < i; j++)
			{
				ofs << str[j];
			}
			ofs << rep;
			str.clear();
		}
		c = '\0';
	}
	if (!str.empty())
		ofs << str;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Nombre d'argument invalid !" << std::endl;
		return 1;
	}

	std::string file = argv[1];
	std::string	chr = argv[2];
	std::string	rep = argv[3];
	std::ifstream	ifs(argv[1]);

	if (!ifs.is_open())
	{
		std::cout << "open fail !" << std::endl;
		return 1;
	}
	if (chr.empty())
	{
		std::cout << "Erreur l'argument 2 ne peux pas etre vide !" << std::endl;
		return 1;
	}
	file += ".replace";
	std::ofstream	ofs(file.c_str());
	if (!ifs.is_open())
	{
		std::cout << "open fail !" << std::endl;
		ifs.close();
		return 1;
	}
	replacefile(ifs, ofs, chr, rep);
	ifs.close();
	ofs.close();
}