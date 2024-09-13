/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:26:45 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/13 21:03:14 by faaraujo         ###   ########.fr       */
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

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>

// Classe BitcoinExchange
class BitcoinExchange {
private:
    std::map<std::string, float> exchangeRates;  // Mapeia a data (string) para o valor do Bitcoin (float)
    
public:
    // Construtor que carrega o banco de dados do arquivo CSV
    BitcoinExchange(const std::string& dbFile) {
        loadDatabase(dbFile);
    }

    // Função para carregar o banco de dados
    void loadDatabase(const std::string& dbFile) {
        std::ifstream file(dbFile);  // Abre o arquivo
        if (!file.is_open()) {
            throw std::runtime_error("Error: Could not open the file " + dbFile);
        }

        std::string line;
        while (std::getline(file, line)) {  // Lê o arquivo linha por linha
            std::istringstream ss(line);
            std::string date;
            float value;

            // Divide a linha em data e valor (esperando formato: "AAAA-MM-DD, valor")
            if (std::getline(ss, date, ',') && (ss >> value)) {
                // Valida a data (aqui você pode adicionar uma função específica para validar o formato da data)
                if (isValidDate(date)) {
                    exchangeRates[date] = value;  // Armazena a data e o valor no map
                } else {
                    std::cerr << "Error: Invalid date format in line: " << line << std::endl;
                }
            } else {
                std::cerr << "Error: Invalid data format in line: " << line << std::endl;
            }
        }

        file.close();  // Fecha o arquivo
    }

    // Função para validar o formato da data (AAAA-MM-DD)
    bool isValidDate(const std::string& date) {
        // Aqui está uma validação simples (você pode expandir para verificar mês, dia, etc.)
        if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
            return false;  // Formato inválido
        }
        return true;  // Formato básico válido
    }

    // Função para obter o valor do Bitcoin para uma data específica
    float getBitcoinValue(const std::string& date) const {
        std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
        if (it != exchangeRates.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Error: Date not found in the database.");
        }
    }
};

int main() {
    try {
        // Exemplo de uso: carregando o banco de dados
        BitcoinExchange exchange("bitcoin_data.csv");

        // Exemplo de consulta do valor de Bitcoin para uma data específica
        std::string date = "2023-09-12";
        float value = exchange.getBitcoinValue(date);
        std::cout << "Valor do Bitcoin em " << date << ": " << value << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
