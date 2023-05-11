#include "BitcoinExchange.hpp"

bool isvalidedate(std::string date, std::map<std::string, std::string> *data)
{
	int annee, mois, jour;
	int anneedata;
	char sep;
	std::istringstream strs(date);
	std::istringstream strsdata(data->begin()->first);

	strs >> annee >> sep >> mois >> sep >> jour;
	strsdata >> anneedata;
	if (annee < anneedata || mois < 1 || mois > 12 || jour < 1 || jour > 31)
		return (false);
	if (mois == 2)
	{
		if (annee % 4 == 0 && (annee % 100 != 0 || annee % 400 ==0))
		{
			if (jour > 29)
				return (false);
		}
		else
		{
			if (jour > 28)
				return (false);
		}
	}
	else if (mois == 4 || mois == 6 || mois == 9 || mois == 11)
	{
		if (jour > 30)
			return (false);

	}
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[31musage ./btc input.txt\033[0m" << std::endl; 
		return (1);
	}
	BitcoinExchange bitcoin;
	bitcoin.inputfile(argv[1]);
}
