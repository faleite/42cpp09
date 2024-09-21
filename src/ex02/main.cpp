/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:35:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/21 21:17:05 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	try
	{
		PmergeMe fordJohn;
		fordJohn.handleInput(argc, argv);
		fordJohn.displayNumbers();
		fordJohn.algoFordJonhsonVector();
		fordJohn.displayNumbers(); // corrigir (after)
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}