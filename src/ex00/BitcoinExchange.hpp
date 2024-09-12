/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:38:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/12 22:01:27 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*
 - Workflow:
  - Armazenar os dados do input em um container std::map (date(key):value)
  - Ler ou armazenar a chave e valor do DB (data.csv)

data.csv (DB)			|		input.txt
--------------------------------------------------------
date,exchange_rate		|		date | value
2009-01-02,0			|		2011-01-03 | 3	
2009-01-05,0			|		2011-01-03 | 2	
2009-01-08,0			|		2011-01-03 | 1	
2009-01-11,0			|		2011-01-03 | 1.2	
2009-01-14,0			|		2011-01-09 | 1	
2009-01-17,0			|		2012-01-11 | -1	
2009-01-20,0			|		2001-42-42	
2009-01-23,0			|		2012-01-11 | 1	
2009-01-26,0			|		2012-01-11 | 2147483648	

*/

#endif // BITCOINEXCHANGE_HPP