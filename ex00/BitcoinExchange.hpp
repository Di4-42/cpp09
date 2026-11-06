#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _db;

		bool	isValidDate(const std::string& date);



	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& source);
		BitcoinExchange& operator=(const BitcoinExchange& source);
		~BitcoinExchange();

};
