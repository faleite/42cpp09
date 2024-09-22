/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:25:57 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/22 13:23:10 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void insertionSortVector(std::vector<int> &myVector, int left, int right);
static void mergeInsertSortVector(std::vector<int> &myVector, int left, int right);
static void mergeVector(std::vector<int> &myVector, int left, int mid, int right);

void PmergeMe::algoFordJonhsonVector()
{
	int length = _intVector.size();
	int sublistSize = std::sqrt(length);
	for (int i = 0; i < length; i += sublistSize) // tamanho das sublistas
		insertionSortVector(_intVector, i, std::min(i + sublistSize - 1, length - 1));
	mergeInsertSortVector(_intVector, 0, length - 1);
}

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
			myVector[k] = L[i++];
		else
			myVector[k] = R[j++];
		++k;
	}
	
	// Copia os elementos restantes de L, se houver
	while (i < num1)
		myVector[k++] = L[i++];
	
	// Copia os elementos restantes de R, se houver
	while (j < num2)
		myVector[k++] = R[j++];
}
