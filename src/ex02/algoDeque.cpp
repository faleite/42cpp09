/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:25:57 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/22 12:52:56 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void insertionSortDeque(std::deque<int> &myDeque, int left, int right);
static void mergeInsertSortDeque(std::deque<int> &myDeque, int left, int right);
static void mergeDeque(std::deque<int> &myDeque, int left, int mid, int right);

void PmergeMe::algoFordJonhsonDeque()
{
	int length = _intDeque.size();
	int sublistSize = std::sqrt(length);
	for (int i = 0; i < length; i += sublistSize) // tamanho das sublistas
		insertionSortDeque(_intDeque, i, std::min(i + sublistSize - 1, length - 1));
	mergeInsertSortDeque(_intDeque, 0, length - 1);
}

static void insertionSortDeque(std::deque<int> &myDeque, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = myDeque[i];
		int j = i - 1;
		
		while (j >= left && myDeque[j] > key)
		{
			myDeque[j + 1] = myDeque[j];
			--j;
		}
		myDeque[j + 1] = key;
	}
}

static void mergeInsertSortDeque(std::deque<int> &myDeque, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeInsertSortDeque(myDeque, left, mid);
		mergeInsertSortDeque(myDeque, mid + 1, right);
		mergeDeque(myDeque, left, mid, right);
	}
}

static void mergeDeque(std::deque<int> &myDeque, int left, int mid, int right) 
{
	int num1 = mid - left + 1;
	int num2 = right - mid;

	// Cria arrays temporários
	std::deque<int> L(num1);
	std::deque<int> R(num2);

	// Copia os dados para os arrays temporários
	for (int i = 0; i < num1; ++i)
		L[i] = myDeque[left + i];
	for (int j = 0; j < num2; ++j)
		R[j] = myDeque[mid + 1 + j];

	// Mescla os arrays temporários de volta no array original
	int i = 0, j = 0, k = left;
	while (i < num1 && j < num2)
	{
		if (L[i] <= R[j])
			myDeque[k] = L[i++];
		else
			myDeque[k] = R[j++];
		++k;
	}
	
	// Copia os elementos restantes de L, se houver
	while (i < num1)
		myDeque[k++] = L[i++];
	
	// Copia os elementos restantes de R, se houver
	while (j < num2)
		myDeque[k++] = R[j++];
}
