/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:26:45 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/15 20:34:13 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Você precisa criar um programa que emita o valor de uma certa quantia de 
bitcoin em uma certa data.

Este programa deve usar um banco de dados no formato csv que representará o preço 
do bitcoin ao longo do tempo. Este banco de dados é fornecido com este assunto.

O programa tomará como entrada um segundo banco de dados, armazenando os 
diferentes preços/datas para avaliar.

Seu programa deve respeitar estas regras:
- O nome do programa é btc.
- Seu programa deve tomar um arquivo como argumento.
- Cada linha neste arquivo deve usar o seguinte formato: "data | valor".
- Uma data válida sempre estará no seguinte formato: Ano-Mês-Dia.
- ​​Um valor válido deve ser um float ou um inteiro positivo, entre 0 e 1000.

Você deve usar pelo menos um contêiner em seu código para validar este
exercício. 
Você deve lidar com possíveis erros com uma mensagem de erro apropriada.

Seu programa usará o valor em seu arquivo de entrada.

Seu programa deve exibir na saída padrão o resultado do valor multiplicado pela 
taxa de câmbio de acordo com a data indicada em seu banco de dados.

Se a data usada na entrada não existir em seu BD, então você deve usar a 
data mais próxima contida em seu BD. Tenha cuidado para usar a data mais 
baixa e não a mais alta.
*/

#include "BitcoinExchange.hpp"

// Função para obter o valor do Bitcoin para uma data específica
// float getBitcoinValue(const std::string& date) const {
//     std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
//     if (it != exchangeRates.end()) {
//         return it->second;
//     } else {
//         throw std::runtime_error("Error: Date not found in the database.");
//     }
// }


int main() 
{
    try 
    {
        BitcoinExchange exchange("data1.csv");
        // exchange.printDatabase();
        exchange.processInputFile("input.txt");
    } 
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
