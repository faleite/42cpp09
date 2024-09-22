/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:06:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/22 15:44:23 by faaraujo         ###   ########.fr       */
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

void PmergeMe::handleInput(int argc, char *argv[])
{
	if (argc == 1)
		throw std::runtime_error("Invalid number of the arguments");

	std::clock_t start = std::clock();
	this->_numElements = argc - 1;
	int arr[this->_numElements];
	for (size_t i = 1; i < this->_numElements; ++i)
		arr[i - 1] = stringToNumber(argv[i]);
	std::clock_t end = std::clock();
	
	double dataManageTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	
	start = std::clock();
	this->_intVector.assign(arr, arr + this->_numElements - 1);
	end = std::clock();
	double pushDataVectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	
	start = std::clock();
	this->_intDeque.assign(arr, arr + this->_numElements - 1);
	end = std::clock();
	double pushDataDequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

	_dequeProcessTime = dataManageTime + pushDataDequeTime;
	_vectorProcessTime = dataManageTime + pushDataVectorTime;
}

// void PmergeMe::displayNumbers(const std::string &msg) const
// {
// 	std::cout << msg;
// 	for (std::deque<int>::const_iterator it = this->_intDeque.begin(); 
// 		it != this->_intDeque.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

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
	
	// std::cout << "Data manage vec: " << _vectorProcessTime << "\n";
	double vectorSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	_vectorProcessTime = _vectorProcessTime + vectorSortTime;
	// std::cout << "sort vec: " << vectorSortTime << "\n";
	std::cout << "Time to process a range of " << _numElements
	<< " elements with std::vector: " << _vectorProcessTime << " us" << std::endl;

	start = std::clock();
	algoFordJonhsonDeque();
	end = std::clock();
	
	// std::cout <<  "Data manage deq: " << _dequeProcessTime << "\n";
	double dequeSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	_dequeProcessTime = _dequeProcessTime + dequeSortTime;
	// std::cout << "sort deq: " << dequeSortTime << "\n";
	std::cout << "Time to process a range of " << _numElements
	<< " elements with std::deque: " << _dequeProcessTime << " us" << std::endl;	
}