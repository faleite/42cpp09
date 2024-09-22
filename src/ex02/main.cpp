/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:35:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/22 15:11:24 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	try
	{
		PmergeMe fordJohn;
		fordJohn.handleInput(argc, argv);
		fordJohn.displayProcess();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}