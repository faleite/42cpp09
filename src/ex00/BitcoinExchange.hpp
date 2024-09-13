/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:38:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/13 21:50:55 by faaraujo         ###   ########.fr       */
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
};


// utilFunctions

bool isValidDate(const std::string &date)
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
	std::ifstream file(dbFile);
	if (!file.is_open())
		throw std::runtime_error("Error:\nCould not open the file " + dbFile);
	
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		float value;
		
		if (std::getline(ss, date, ',') && (ss >> value))
		{
			isValidDate(date);
		}
	}
}
#endif // BITCOINEXCHANGE_HPP