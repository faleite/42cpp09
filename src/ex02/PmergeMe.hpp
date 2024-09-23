/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:06:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/23 12:43:16 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits.h>
#include <cmath> // std::sqrt
#include <ctime>
#include <stdexcept>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_intVector;
		std::deque<int>		_intDeque;
		unsigned int		_numElements;
		double 				_vectorProcessTime;
		double 				_dequeProcessTime;
		double 				_vectorDataManageTime;
		double 				_dequeDataManageTime;
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copyObj);
		PmergeMe &operator=(const PmergeMe &assignCopy);
		~PmergeMe();

		void dataManagement(int argc, char *argv[]);
		void displayNumbers(const std::string &msg) const;
		void displayProcess();
		
		void algoFordJonhsonVector();
		void algoFordJonhsonDeque();
};

// Utils Functions
int		stringToNumber(const std::string &str);
bool	emptyWhitespace(const char *str);

#endif // PMERGEME_HPP