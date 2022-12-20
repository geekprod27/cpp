#include <iostream>
#include <fstream>
#include <ctype.h>

void	replacefile(std::ifstream&	ifs, std::ofstream&	ofs, std::string& chr, std::string& rep)
{
	char 		c;
	std::string str;
	size_t		i = 0;
	size_t		save = 0;
	while (!ifs.eof())
	{
		ifs.get(c);
		str += c;
		i = str.find(chr, save);
		if (i != std::string::npos)
		{
			for(size_t j = 0; j < i; j++)
			{
				ofs << str[j];
			}
			ofs << rep;
			save = i + rep.size();
			str.clear();
		}
	}
	while (str[save + 1])
	{
		ofs << str[save];
		save++;
	}
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