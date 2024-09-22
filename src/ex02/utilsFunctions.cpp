/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsFunctions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:00:54 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/22 13:01:26 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool emptyWhitespace(const char *str)
{
	if (str == NULL)
		return (true);
	while (*str)
	{
		if (!isspace((unsigned char)*str))
			return (false);
		str++;
	}
	return (true);
}

int stringToNumber(const std::string &str)
{
	if (emptyWhitespace(str.c_str()))
		throw std::runtime_error("Empty argument");
		
	std::string copyStr = str;
	copyStr.erase(copyStr.find_last_not_of(" \n\r\t") + 1);
	
	char *end;
	long num = std::strtol(copyStr.c_str(), &end, 10);
	
	if (*end != '\0' || (num < 0 || num > INT_MAX))
		throw std::runtime_error("Invalid argument: " + str);
		
	return (static_cast<int>(num));
}