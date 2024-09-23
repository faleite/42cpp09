/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:38:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/23 14:08:07 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// CANONICAL FORM

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copyObj)
{
	*this = copyObj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assignCopy)
{
	(void)assignCopy;
	return (*this);
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
		int i = 0;
		while (std::getline(file, line))
		{
			std::istringstream ss(line);
			std::string date;
			float value;
			if (i == 0 && line == "date,exchange_rate")
				continue ;
			else if (std::getline(ss, date, ',') && (ss >> value))
			{
				if (!dateFormat(date) || !validDate(date))
					throw std::runtime_error("Error:\nDate: [" + date + "] invalid");
				if (value < 0 || value > FLT_MAX)
					throw std::runtime_error("Error:\nValue: [" + line + "] invalid");
				dataStore[date] = value;
			}
			else
				throw std::runtime_error("Error:\nLine: [" + line + "] invalid");
			i++;
		}
	}
	catch (const std::exception &e)
	{
		file.close();
		throw;
	}
	file.close();
}

void BitcoinExchange::processInputFile(const std::string &inputFile)
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	try
	{
		std::string line;
		int i = 0;
		while (std::getline(file, line))
		{
			std::istringstream ss(line);
			std::string date;
			float value;
			if (i == 0 && line == "date | value")
				continue ;
			else if (std::getline(ss, date, '|') && (ss >> value))
				this->outputResult(date, value);
			else
				std::cout << "Error: bad input => " << line << std::endl;
			i++;
		}
	}
	catch (const std::exception &e)
	{
		file.close();
		throw;
	}
	file.close();
}

void BitcoinExchange::outputResult(std::string &date, float value)
{
	date.erase(date.find_last_not_of(" \n\r\t") + 1);
	int status = validateInput(date, value);
	
	float result = this->calculateBitcoin(date, value);
	
	switch (status)
	{
		case VALID:
			std::cout << date << " => " << value << " = " << result <<  std::endl;
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

float BitcoinExchange::calculateBitcoin(const std::string &date, float value)
{
	std::map<std::string, float>::iterator it = dataStore.lower_bound(date);
	if (it == dataStore.end() || (it != dataStore.begin() && it->first != date))
	{
		if (it == dataStore.begin())
			throw std::runtime_error("Error:\nNo valid date found in the database");
		--it;
	}
	return (fabs(it->second * value));
}

void BitcoinExchange::getDatabase() const
{
	std::map<std::string, float>::const_iterator it;
	for (it = dataStore.begin(); it != dataStore.end(); ++it)
	{
		std::cout << it->first << "," << std::fixed << 
		std::setprecision(2) << it->second << std::endl;
	}
}
