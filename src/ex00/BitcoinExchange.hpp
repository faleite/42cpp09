/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:38:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/23 10:35:21 by faaraujo         ###   ########.fr       */
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
#include <cmath>
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
		// why they chose to use this container and not another?
		std::map<std::string, float> dataStore; // for csv file
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copyObj);
		BitcoinExchange &operator=(const BitcoinExchange &assignCopy);
		~BitcoinExchange();

		void	storeDatabase(const std::string &dbFile);
		void	processInputFile(const std::string &inputFile);
		void	outputResult(std::string &date, float value);
		void	getDatabase() const;
		float	calculateBitcoin(const std::string &date, float value);
};

// utilFunctions
bool	dateFormat(const std::string &date);
bool	validDate(const std::string &date);
int		validateInput(const std::string &date, float value);

#endif // BITCOINEXCHANGE_HPP