/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:06:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/23 12:43:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

// Member Functions

void PmergeMe::dataManagement(int argc, char *argv[])
{
	if (argc == 1)
		throw std::runtime_error("Invalid number of the arguments");

	std::clock_t start = std::clock();
	this->_numElements = argc - 1;
	int arr[this->_numElements];
	for (size_t i = 0; i < this->_numElements; ++i)
		arr[i] = stringToNumber(argv[i + 1]);
	std::clock_t end = std::clock();
	
	double dataManageTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	
	start = std::clock();
	this->_intVector.assign(arr, arr + this->_numElements);
	end = std::clock();
	double pushDataVectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	
	start = std::clock();
	this->_intDeque.assign(arr, arr + this->_numElements);
	end = std::clock();
	double pushDataDequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

	_dequeDataManageTime = dataManageTime + pushDataDequeTime;
	_vectorDataManageTime = dataManageTime + pushDataVectorTime;
}

void PmergeMe::displayNumbers(const std::string &msg) const
{
	std::cout << msg;
	for (std::vector<int>::const_iterator it = this->_intVector.begin(); 
		it != this->_intVector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::displayProcess()
{
	displayNumbers("before: ");
	
	std::clock_t start = std::clock();
	algoFordJonhsonVector();
	std::clock_t end = std::clock();
	
	displayNumbers("After: ");
	
	double vectorSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	_vectorProcessTime = _vectorDataManageTime + vectorSortTime;

	start = std::clock();
	algoFordJonhsonDeque();
	end = std::clock();
	
	double dequeSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	_dequeProcessTime = _dequeDataManageTime + dequeSortTime;

	std::cout << "Time to process a range of " << _numElements
	<< " elements with std::vector: \n"
	<< "		  Vector Data Management Time: " << _vectorDataManageTime << "\n"
	<< "		  Vector Sorting Time: " << vectorSortTime << "\n"
	<< "Total Vector Processing Time: " << _vectorProcessTime << " ms" << std::endl;
	
	std::cout << "Time to process a range of " << _numElements
	<< " elements with std::deque: " << "\n"
	<< "		  Deque Data Management Time: " << _dequeDataManageTime << "\n"
	<< "		  Deque Sorting Time: " << dequeSortTime << "\n"
	<< "Total Deque Processing: " << _dequeProcessTime << " ms" << std::endl;
}
