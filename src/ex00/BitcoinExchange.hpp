/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:38:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/14 16:36:27 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <map>
#include <iomanip>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		std::map<std::string, float> dataStore; // para csv file
	public:
		BitcoinExchange(const std::string &dbFile); // carrega o DB
		// BitcoinExchange(const BitcoinExchange &copyObj);
		// BitcoinExchange &operator=(const BitcoinExchange &assignCopy);
		~BitcoinExchange();

		void storeDatabase(const std::string &dbFile);
		void printDatabase() const;
};


// utilFunctions

bool dateFormat(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	return (true);
}

// CANONICAL FORM

BitcoinExchange::BitcoinExchange(): dataStore() {}

BitcoinExchange::BitcoinExchange(const std::string &dbFile): dataStore() 
{
	storeDatabase(dbFile);
}

BitcoinExchange::~BitcoinExchange() {}

// CLASS FUNCTIONS

void BitcoinExchange::storeDatabase(const std::string &dbFile)
{
	// separar para usar no input.txt
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error:\nCould not open the file " + dbFile);
	//	
	try
	{
		std::string line;
		if (!std::getline(file, line) || line != "date,exchange_rate")
		{
			throw std::runtime_error("Error:\nInvalid data");
		}
		while (std::getline(file, line))
		{
			std::istringstream ss(line);
			std::string date;
			float value;
			if (std::getline(ss, date, ',') && (ss >> value))
			{
				if (!dateFormat(date))
					throw std::runtime_error("Error:\nDate: [" + date + "] invalid");
				dataStore[date] = value;
			}
			else
				throw std::runtime_error("Error:\nData: [" + line + "] invalid");
		}
	}
	catch (const std::exception &e)
	{
		file.close();
		throw;
	}
	file.close();
}

void BitcoinExchange::printDatabase() const
{
	std::map<std::string, float>::const_iterator it;
	for (it = dataStore.begin(); it != dataStore.end(); ++it)
	{
		std::cout << it->first << "," << std::fixed << 
		std::setprecision(2) << it->second << std::endl;
	}
}

#endif // BITCOINEXCHANGE_HPP