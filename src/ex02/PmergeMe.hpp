/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:06:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/21 21:16:49 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>

#include <string>
#include <sstream>
#include <cstdlib>
// #include <iomanip>
#include <limits.h>
#include <cmath> // std::sqrt
#include <stdexcept>

#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_intVector;
		std::deque<int>		_intDeque;
		// std::string			_unsortedNbrs;
		// std::string			_sortedNbrs;
		double 				_vectorSortTime;
		double 				_dequeSortTime;
		// int					_ac;
		// char				**av;
		
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copyObj);
		PmergeMe &operator=(const PmergeMe &assignCopy);
		~PmergeMe();

		void handleInput(int argc, char *argv[]);
		void displayNumbers() const;
		// void displayUnsortedNbrs() const;
		// void displaySortedNbrs() const;
		// void displaySortedTime() const;
		
		// void algoFordJonhsonVector(std::vector<int> &numbers);
		void algoFordJonhsonVector();
		// void algoFordJonhsonDeque(std::deque<int> &numbers);
};

// Canonical Form

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copyObj)
{
	(void)copyObj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &assignCopy)
{
	(void)assignCopy;
	return (*this);
}

PmergeMe::~PmergeMe() {}

// Utils Functions

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

// Member Functions

void PmergeMe::handleInput(int argc, char *argv[])
{
	if (argc == 1)
		throw std::runtime_error("Invalid number of the arguments");

	int arr[argc - 1];
	for (int i = 1; i < argc; ++i)
		arr[i - 1] = stringToNumber(argv[i]);
		
	this->_intVector.assign(arr, arr + argc - 1);
	this->_intDeque.assign(arr, arr + argc - 1);
}

void PmergeMe::displayNumbers() const
{
	std::cout << "before: ";
	for (std::vector<int>::const_iterator it = this->_intVector.begin(); 
		it != this->_intVector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/*
for (size_t i = 1; i < _intVector.size(); i++)
	{
		int key = _intVector[i];
		int j = i - 1;
		
		while (j >= 0 && _intVector[j] > key)
		{
			_intVector[j + 1] = _intVector[j];
			j--;
		}
		_intVector[j + 1] = key;
	}
*/
static void insertionSortVector(std::vector<int> &myVector, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = myVector[i];
		int j = i - 1;
		
		while (j >= left && myVector[j] > key)
		{
			myVector[j + 1] = myVector[j];
			--j;
		}
		myVector[j + 1] = key;
	}
}

static void mergeVector(std::vector<int> &myVector, int left, int mid, int right) 
{
	int num1 = mid - left + 1;
	int num2 = right - mid;

	// Cria arrays temporários
	std::vector<int> L(num1);
	std::vector<int> R(num2);

	// Copia os dados para os arrays temporários
	for (int i = 0; i < num1; ++i)
		L[i] = myVector[left + i];
	for (int j = 0; j < num2; ++j)
		R[j] = myVector[mid + 1 + j];

	// Mescla os arrays temporários de volta no array original
	int i = 0, j = 0, k = left;
	while (i < num1 && j < num2)
	{
		if (L[i] <= R[j])
		{
			myVector[k] = L[i];
			++i;
		}
		else
		{
			myVector[k] = R[j];
			++j;
		}
		++k;
	}
	
	// Copia os elementos restantes de L, se houver
	while (i < num1)
	{
		myVector[k] = L[i];
		++i;
		++k;
	}
	
	// Copia os elementos restantes de R, se houver
	while (j < num2)
	{
		myVector[k] = R[j];
		++j;
		++k;
	}
}

static void mergeInsertSortVector(std::vector<int> &myVector, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeInsertSortVector(myVector, left, mid);
		mergeInsertSortVector(myVector, mid + 1, right);
		mergeVector(myVector, left, mid, right);
	}
}

void PmergeMe::algoFordJonhsonVector()
{
	int length = _intVector.size();
	int sublistSize = std::sqrt(length);
	for (int i = 0; i < length; i += sublistSize) // tamanho das sublistas
		insertionSortVector(_intVector, i, std::min(i + sublistSize - 1, length - 1));
	mergeInsertSortVector(_intVector, 0, length - 1);
}

#endif // PMERGEME_HPP