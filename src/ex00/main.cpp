/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:26:45 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/19 17:14:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments\n"
        << "try: ./btc file" << std::endl;
        return (1);
    }
    try 
    {
        BitcoinExchange btc;
        btc.storeDatabase("data.csv");
        btc.processInputFile(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }   
    return (0);
}
