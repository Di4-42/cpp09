#pragma once

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
	private:
		

	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& source);
		BitcoinExchange& operator=(const BitcoinExchange& source);
		~BitcoinExchange();

		bool	isValidDate(const std::string& date);
		bool	isValidValue(const std::string& bitcoin, double& out);
		double	getRateForDate(const std::string& date);
		void	loadDatabase(const std::string& filename);
		void	processInput(const std::string& filename);
		std::map<std::string, double> _db;
};
