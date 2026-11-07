#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source) : _db(source._db)
{
	std::cout << "Copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &source)
		_db = source._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor called" << std::endl;
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')  //"2024-02-09"
		return false;

	for(int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)     //pour accepter les "-"
			continue;

		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	int	year = std::atoi(date.substr(0, 4).c_str());  //recupere un pointeur vers son texte
	int	month = std::atoi(date.substr(5, 2).c_str()); // // "04" devient int 4
	int	day = std::atoi(date.substr(8, 2).c_str());
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 1 || month < 1 || month > 12)
		return false;

	bool bissextile = false;

	if (year % 400 == 0)
		bissextile = true;
	else if (year % 100 == 0)
		bissextile = false;
	else if (year % 4 == 0)
		bissextile = true;

	if (bissextile)
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])  //les mois vont jusqua 12 || indices du tableau jusqua 11
		return false;
	return true;

}
	/* 1900 -> divisible par 100 pas par 400 -> 28 fevrier
	   2000 -> divisible par 400 			 -> 29 fevrier
	   2100 -> divisible par 100 pas par 400 -> 28 fevrier,
	*/

bool	BitcoinExchange::isValidValue(const std::string& bitcoin, double& out)
{
	if (bitcoin.empty())
	{
		std::cout << "Error: bad input" << std::endl;
		return false;
	}

	char* endptr;
	double value = std::strtod(bitcoin.c_str(), &endptr);

	if (endptr == bitcoin.c_str() || *endptr != '\0' || value != value)
	{
		std::cout << "Error: bad input" << std::endl;
		return false;
	}

	if (value < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return false;
	}

	if (value > 1000)
	{
		std::cout << "Error: too large number" << std::endl;
		return false;
	}

	out = value;
	return true;
}

double	BitcoinExchange::getRateForDate(const std::string& date)
{
	std::map<std::string, double>::iterator it = _db.lower_bound(date);

	if (it == _db.end() || it->first != date)
	{
		if (it == _db.begin())
			throw std::runtime_error("Error: bad input => " + date);
		--it;
	}
	return it->second;
}

