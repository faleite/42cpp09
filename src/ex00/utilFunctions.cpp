/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilFunctions.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:40:06 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/23 10:14:30 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// utilFunctions

bool dateFormat(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	return (true);
}

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
	if (value < 0)
		return (NEGATIVE_VALUE);
	if (value > 1000)
		return (TOO_LARGE_VALUE);
	return (VALID);
}
