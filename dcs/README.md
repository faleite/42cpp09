# C++
***(Modulo 09)***

## Workflow
<details>
  <summary>Desenvolvimento</summary>

**Estrutura de pastas:**
```
ex00/
├── Makefile
├── main.cpp
├── BitcoinExchange.cpp
├── BitcoinExchange.hpp
└── input.txt (Exemplo)
```
### Desenvolvimento:
- Passo 1: Leitura de Arquivos
  - Implementar a leitura do arquivo de entrada (input.txt) e da base de dados CSV.
  - Utilizar containers apropriados para armazenar os dados.
- Passo 2: Validação de Dados
  - Implementar a validação da data no formato correto.
  - Verificar se o valor está dentro do intervalo permitido (0 a 1000).
- Passo 3: Cálculo das Taxas
  - Implementar a busca da taxa de câmbio correspondente à data.
  - Se a data não estiver presente no banco de dados, localizar a data anterior mais próxima.
  - Realizar o cálculo e armazenar os resultados.
- Passo 4: Tratamento de Erros
  - Implementar mensagens de erro claras para:
  - Data inválida.
  - Valores fora dos limites.
  - Falha na leitura do arquivo.
- Passo 5: Exibição dos Resultados
  - Exibir os resultados corretamente formatados.
  - Seguir o padrão de saída fornecido no exemplo (incluindo mensagens de erro quando apropriado).
---
  - Armazenar os dados do input em um container std::map (date(key):value)
  - Ler ou armazenar a chave e valor do DB (data.csv)
   - Este banco de dados é fornecido com o subject.

```
data.csv (DB)			|		input.txt
--------------------------------------------------------
date,exchange_rate|		date | value
2009-01-02,0			|		2011-01-03 | 3	
2009-01-05,0			|		2011-01-03 | 2	
2009-01-08,0			|		2011-01-03 | 1	
2009-01-11,0			|		2011-01-03 | 1.2	
2009-01-14,0			|		2011-01-09 | 1	
2009-01-17,0			|		2012-01-11 | -1	
2009-01-20,0			|		2001-42-42	
2009-01-23,0			|		2012-01-11 | 1	
2009-01-26,0			|		2012-01-11 | 2147483648	
```

```
ex00/
├── Makefile
├── main.cpp
├── BitcoinExchange.cpp
├── BitcoinExchange.hpp
└── input.txt (Exemplo)
```

https://medium.com/@sofia.huppertz/cpp09-school42-1efa42df7803
</details>
<details>
  <summary>Estrutura</summary>

### Estrutura do projeto:
1. Classe BitcoinExchange:
- Responsabilidade: Centralizar a lógica do programa.
- Métodos:
  - [x] Carregar a base de dados de câmbio em um container (ex: std::map para mapear a data para a taxa de câmbio).
  - [x] Processar o arquivo de entrada.
  - [x] Calcular o valor de Bitcoin com base na data e taxa de câmbio.
  - [x] Manipular e validar datas.
  - [X] Comparar datas para encontrar a mais próxima.
  - [x] Exibir DB
- Atributos:
  - [x] Um container (como std::map ou std::vector) para armazenar as taxas de câmbio.
2. Funções Utilitárias (fora das classes):
- Validação do arquivo de Entrada:
  - [x] Funções responsáveis por abrir e ler arquivos (CSV e o arquivo de entrada).
  - [x] Validar o formato da data.
  - [x] Validar data (dia, mês, ano).
  - [x] Validar valor (0 a 1000).

### Exemplo de Estrutura:
```cpp
// BitcoinExchange.hpp
class BitcoinExchange {
private:
    std::map<std::string, float> exchangeRates;  // Para armazenar as taxas por data
public:
    BitcoinExchange(const std::string& dbFile);  // Construtor que carrega o DB
    void processFile(const std::string& inputFile);  // Processa o arquivo de entrada
    float calculate(const std::string& date, float value);  // Calcula o valor com base na data
};

// Date.hpp
class Date {
public:
    static bool isValid(const std::string& dateStr);  // Valida o formato da data
    static bool isBefore(const std::string& date1, const std::string& date2);  // Compara datas
};

// Funções utilitárias
bool validateValue(float value);  // Valida se o valor está entre 0 e 1000
std::map<std::string, float> loadExchangeRates(const std::string& filename);  // Carrega as taxas
```

</details>

<details>
  <summary>Subject</summary>
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
</details>

<!-- [↑ Index ↑](#index) -->

