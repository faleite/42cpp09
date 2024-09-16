/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:38:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/16 19:25:52 by faaraujo         ###   ########.fr       */
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
#include <float.h>

#define DATE_MIN 2009

enum validation
{
	VALID,
    INVALID_DATE,
    NEGATIVE_VALUE,
    TOO_LARGE_VALUE,
    BAD_INPUT
};

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
		void processInputFile(const std::string &inputFile);
};

// utilFunctions

bool dateFormat(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	return (true);
}

// std::cout << year << ":" << month << ":" << day << delimiter << "\n";
bool validDate(const std::string &date)
{
	std::istringstream ss(date);
	int year, month, day;
	char delimiter;
	ss >> year >> delimiter >> month >> delimiter >> day;
	if (year < DATE_MIN || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month ==  9 || month == 11) && day > 30)
		return (false);
	if (month == 2)
	{
		bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (leap ? 29 : 28))
			return (false);
	}
	return (true);
}

int validateInput(const std::string &date, float value)
{
	if (!dateFormat(date) || !validDate(date))
		return (INVALID_DATE);
	if (value <= 0)
		return (NEGATIVE_VALUE);
	if (value >= 1000)
		return (TOO_LARGE_VALUE);
	return (VALID);
}

void outputResult(std::string &date, float value)
{
	date.erase(date.find_last_not_of(" \n\r\t") + 1);
	int result = validateInput(date, value);
	switch (result)
	{
		case VALID:
			std::cout << date << " => " << value << "\n";
			break;
		case INVALID_DATE:
			std::cout << "Error: bad input => " << date << std::endl;
			break;
		case NEGATIVE_VALUE:
			std::cout << "Error: not a positve number." << std::endl;
			break;
		case TOO_LARGE_VALUE:
			std::cout << "Error: too large a number." << std::endl;
			break;
	}
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
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file " + dbFile);
	try
	{
		std::string line;
		if (!std::getline(file, line) || line != "date,exchange_rate")
		{
			throw std::runtime_error("Error: Data: [" + line + "] invalid");
		}
		while (std::getline(file, line))
		{
			std::istringstream ss(line);
			std::string date;
			float value;
			if (std::getline(ss, date, ',') && (ss >> value))
			{
				if (!dateFormat(date) || !validDate(date))
					throw std::runtime_error("Error:\nDate: [" + date + "] invalid");
				if (value < 0 || value > FLT_MAX)
					throw std::runtime_error("Error:\nValue: [" + line + "] invalid");
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

void BitcoinExchange::processInputFile(const std::string &inputFile)
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	try
	{
		std::string line;
		if (!std::getline(file, line) || line != "date | value")
		{
			throw std::runtime_error("Error:\nData: [" + line + "] invalid");
		}
		while (std::getline(file, line))
		{
			std::istringstream ss(line);
			std::string date;
			float value;
			if (std::getline(ss, date, '|') && (ss >> value))
				outputResult(date, value);
			else
				std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		file.close();
		throw;
	}
	file.close();
}

#endif // BITCOINEXCHANGE_HPP