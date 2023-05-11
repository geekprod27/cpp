#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
	std::ifstream ifs;
  	ifs.open ("data.csv");
	if (!ifs.is_open() || !ifs.good())
	{
		std::cout << "\033[31mFailed to open data.csv\033[0m" << std::endl;
		exit (1);
	}
	std::string date, txt, value;
	while (ifs)
	{
		getline(ifs, txt);
		if (txt.size() == 0 && !ifs.eof())
		{
			std::cout << "\033[31mFailed to read data.csv\033[0m" << std::endl;
			exit (1);
		}
		if (txt.empty())
			continue;
		value = txt;
		value.erase(0, value.find(',')+1);
		date = txt;
		date.erase(date.find(','));
		_data.insert(std::pair<std::string, std::string>(date, value));
		date.clear();
		value.clear();
		txt.clear();
		
	}
	ifs.close();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		_data = rhs._data;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	BitcoinExchange::inputfile(char *input)
{
	std::string date, txt, value;
	std::ifstream ifs;
	ifs.open (input);
	if (!ifs.is_open() || !ifs.good())
	{
		std::cout << "\033[31mFailed to open " << input << "\033[0m" << std::endl;
		exit (1);
	}
	while (ifs)
	{
		getline(ifs, txt);
		if (txt.size() == 0 && !ifs.eof())
		{
			std::cout << "\033[31mFailed to read " << input << "\033[0m" << std::endl;
			exit (1);
		}
		if (txt.empty() || txt == "date | value")
			continue;
		date = txt;
		if (date.find('|') != std::string::npos)
		date.erase(date.find('|'));
		value = txt;
		value.erase(0, value.find('|')+1);
		std::map<std::string, std::string>::iterator it = _data.lower_bound(date);
		it--;
		if (date.find(' ') != std::string::npos)
			date.erase(date.find(' '));
		if (isvalidedate(date, &_data))
		{
			if (strtof(value.c_str(), NULL) > 0 && strtof(value.c_str(), NULL) < 1000)
				std::cout << date << " => " << value << " = " << strtof(value.c_str(), NULL) * strtof((it)->second.c_str(), NULL) << std::endl;
			else
			{
				if (strtof(value.c_str(), NULL) <= 0)
					std::cout << "Error: not a positive number." << std::endl;
				else
					std::cout << "Error: too large a number." << std::endl;
			}
		}
		else
			std::cout << "Error: bad input => " << date << std::endl;
		date.clear();
		value.clear();
		txt.clear();
	}
	ifs.close();
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */