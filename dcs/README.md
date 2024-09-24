# C++
***(Modulo 09)***

## Workflow ex00
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
└── data.csv (data base)
```

<!-- https://medium.com/@sofia.huppertz/cpp09-school42-1efa42df7803 -->

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

<details>
  <summary>Utils</summary>

```cpp
// Função para obter o valor do Bitcoin para uma data específica
float getBitcoinValue(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
    if (it != exchangeRates.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Error: Date not found in the database.");
    }
}
```

</details>

## Workflow ex02
<details>
  <summary>Desenvolvimento</summary>

### Etapas Iniciais para o Desenvolvimento do Projeto

1. **Definição do Algoritmo Merge-Insert Sort:**
   - [x] Pesquise e entenda o algoritmo Ford-Johnson (merge-insert sort).
   - [x] Planeje a implementação do algoritmo para dois contêineres diferentes (por exemplo, `std::vector` e `std::list`).

2. **Planejamento das Funções Principais:**
   - [x] leitura e validação dos argumentos de entrada.
   - [x] exibir a sequência de inteiros não classificados.
   - [x] aplicar o algoritmo de ordenação usando o primeiro contêiner.
   - [x] aplicar o algoritmo de ordenação usando o segundo contêiner.
   - [x] medir e exibir o tempo de execução de cada contêiner.
   - [x] tratamento de erros e exibição de mensagens de erro.

3. **Especificação dos Arquivos de Cabeçalho:**
   - [x] Defina as classes e funções no arquivo `PmergeMe.hpp`

4. **Implementação do Arquivo Principal:**
   - [x] Estruture o arquivo `main.cpp` para inicializar o programa e chamar as funções principais

### Próximos Passos
- [ ] Implementar as funções definidas no arquivo de cabeçalho.
- [ ] Testar o programa com diferentes sequências de inteiros.
- [ ] Otimizar o código e corrigir possíveis bugs.

Essa estrutura inicial deve fornecer uma base sólida para o desenvolvimento do projeto conforme as diretrizes fornecidas.

</details>

<details>
  <summary>Subject</summary>
Você deve criar um programa com estas restrições:
- O nome do programa é PmergeMe.
- Seu programa deve ser capaz de usar uma sequência de inteiros 
positivos como argumento.
- Seu programa deve usar o algoritmo merge-insert sort para classificar a 
sequência de inteiros positivos.

Para esclarecer, sim, você precisa usar o algoritmo Ford-Johnson.

- Se ocorrer um erro durante a execução do programa, uma mensagem de erro 
deve ser exibida no erro padrão.

Você deve usar pelo menos dois contêineres diferentes em seu código para
validar este exercício. Seu programa deve ser capaz de lidar com pelo
menos 3000 inteiros diferentes.

É altamente recomendável implementar seu algoritmo para cada contêiner
e, portanto, evitar o uso de uma função genérica.

Aqui estão algumas diretrizes adicionais sobre as informações que você deve 
exibir linha por linha na saída padrão:
- Na primeira linha, você deve exibir um texto explícito seguido pela sequência 
de inteiros positivos não classificados.
- Na segunda linha, você deve exibir um texto explícito seguido pela sequência 
de inteiros positivos classificados.
- Na terceira linha você deve exibir um texto explícito indicando o tempo usado 
pelo seu algoritmo especificando o primeiro contêiner usado para classificar a 
sequência de inteiros positivos.
- Na última linha você deve exibir um texto explícito indicando o tempo usado pelo 
seu algoritmo especificando o segundo contêiner usado para classificar a sequência 
de inteiros positivos.

O formato para a exibição do tempo usado para executar sua classificação
é livre, mas a precisão escolhida deve permitir ver claramente a diferença 
entre os dois contêineres usados.

A indicação do tempo é deliberadamente estranha neste exemplo.
É claro que você tem que indicar o tempo usado para executar todas as suas
operações, tanto a parte de classificação quanto a parte de gerenciamento de dados.

O gerenciamento de erros relacionados a duplicatas é deixado a seu critério.
</details>

<details>
  <summary>Algoritimos</summary>

## Mediana
A mediana é um valor que separa um conjunto de números em duas metades iguais, de tal forma que metade dos números é menor ou igual a esse valor e a outra metade é maior ou igual a ele. Para encontrar a mediana em um array de números desordenados, você precisa primeiro ordenar o array. A definição da mediana depende se o número de elementos no array é ímpar ou par:

1. **Número Ímpar de Elementos**:
   - A mediana é o elemento do meio do array ordenado.
   - Por exemplo, para o array `[3, 1, 4, 1, 5]`, após ordenar `[1, 1, 3, 4, 5]`, a mediana é `3`.

2. **Número Par de Elementos**:
   - A mediana é a média dos dois elementos do meio do array ordenado.
   - Por exemplo, para o array `[3, 1, 4, 1]`, após ordenar `[1, 1, 3, 4]`, a mediana é `(1 + 3) / 2 = 2`.

### Passos para Encontrar a Mediana

1. **Ordenar o Array**:
   - Use um algoritmo de ordenação, como quicksort ou mergesort, para ordenar o array.

2. **Encontrar o Elemento do Meio**:
   - Se o número de elementos `n` for ímpar, a mediana é o elemento na posição `n/2` (índice zero-based).
   - Se o número de elementos `n` for par, a mediana é a média dos elementos nas posições `n/2 - 1` e `n/2`.


***Exemplo de como encontrar a mediana de um array de números desordenados em C++:***

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort

double findMedian(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end()); // Ordena o array
    int n = nums.size();
    if (n % 2 == 0) {
        // Se o número de elementos é par, retorna a média dos dois elementos do meio
        return (nums[n/2 - 1] + nums[n/2]) / 2.0;
    } else {
        // Se o número de elementos é ímpar, retorna o elemento do meio
        return nums[n/2];
    }
}

int main() {
    std::vector<int> nums = {3, 1, 4, 1, 5};
    double median = findMedian(nums);
    std::cout << "A mediana é: " << median << std::endl;
    return 0;
}
```

*A mediana é uma medida de tendência central que é menos afetada por valores extremos (outliers) do que a média, tornando-a útil em muitas aplicações estatísticas e de análise de dados.*

[↑ Algoritimos ↑](#mediana)

## Binary Search
A **busca binária** (ou **binary search**) é um algoritmo de pesquisa que encontra a posição de um valor alvo dentro de um array ordenado. O algoritmo compara o valor alvo ao elemento do meio do array. Se eles não são iguais, a metade na qual o alvo não pode estar é descartada e a busca continua na metade restante, até que o valor alvo seja encontrado ou o intervalo de busca se torne vazio.

### Passos do Algoritmo

1. **Inicialização**:
   - Defina dois índices, `low` e `high`, que representam os limites inferior e superior do intervalo de busca. Inicialmente, `low` é 0 e `high` é o índice do último elemento do array.

2. **Iteração**:
   - Enquanto `low` for menor ou igual a `high`:
     1. Calcule o índice do meio: `mid = low + (high - low) / 2`.
     2. Compare o elemento no índice `mid` com o valor alvo:
        - Se o elemento no índice `mid` for igual ao valor alvo, o alvo foi encontrado e o índice `mid` é retornado.
        - Se o elemento no índice `mid` for menor que o valor alvo, ajuste `low` para `mid + 1` para continuar a busca na metade superior.
        - Se o elemento no índice `mid` for maior que o valor alvo, ajuste `high` para `mid - 1` para continuar a busca na metade inferior.

3. **Conclusão**:
   - Se `low` ultrapassar `high`, o valor alvo não está presente no array e o algoritmo retorna um valor indicativo de falha (geralmente -1).

***Exemplo de implementação da busca binária em C++:***

```cpp
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Elemento encontrado
        } else if (arr[mid] < target) {
            low = mid + 1; // Continuar na metade superior
        } else {
            high = mid - 1; // Continuar na metade inferior
        }
    }

    return -1; // Elemento não encontrado
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int result = binarySearch(arr, target);

    if (result != -1) {
        std::cout << "Elemento encontrado no índice: " << result << std::endl;
    } else {
        std::cout << "Elemento não encontrado." << std::endl;
    }

    return 0;
}
```

### Complexidade

- **Tempo**: O(log n), onde n é o número de elementos no array. A cada iteração, o intervalo de busca é reduzido pela metade.
- **Espaço**: O(1) para a versão iterativa, pois utiliza apenas algumas variáveis adicionais.

[↑ Algoritimos ↑](#mediana)

## Insertion Sort - simples
O **insertion sort**  (ou ordenação por inserção) ordena um array de números iterativamente, inserindo cada novo elemento na posição correta em relação aos elementos já ordenados. A ideia é dividir o array em duas partes: a parte ordenada e a parte não ordenada. Inicialmente, a parte ordenada contém apenas o primeiro elemento, e a parte não ordenada contém o restante dos elementos. Em cada iteração, o próximo elemento da parte não ordenada é removido e inserido na posição correta na parte ordenada.

### Passos do Algoritmo

1. **Inicialização**:
   - Considere o primeiro elemento do array como a parte ordenada.

2. **Iteração**:
   - Para cada elemento `i` do array, começando do segundo elemento (índice 1):
     1. Armazene o valor do elemento atual (`key`).
     2. Compare `key` com os elementos da parte ordenada (à esquerda de `i`).
     3. Desloque os elementos maiores que `key` uma posição para a direita.
     4. Insira `key` na posição correta.

3. **Conclusão**:
   - Repita o processo até que todos os elementos tenham sido inseridos na parte ordenada.

***Exemplo de implementação do insertion sort em C++:***

```cpp
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Desloca os elementos da parte ordenada que são maiores que key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        // Insere key na posição correta
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    insertionSort(arr);

    std::cout << "Array ordenado: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Complexidade

- **Tempo**:
  - **Melhor caso**: O(n) - Ocorre quando o array já está ordenado.
  - **Pior caso**: O(n^2) - Ocorre quando o array está ordenado em ordem inversa.
  - **Caso médio**: O(n^2) - Em média, o algoritmo precisa comparar e deslocar elementos para cada inserção.

- **Espaço**: O(1) - O algoritmo é in-place, ou seja, não requer espaço adicional significativo além das variáveis temporárias.

### Resumo

O insertion sort é um algoritmo de ordenação simples e eficiente para listas pequenas ou quase ordenadas. Ele funciona construindo a lista ordenada um elemento de cada vez, inserindo cada novo elemento na posição correta em relação aos elementos já ordenados. Embora tenha complexidade de tempo O(n^2) no pior caso, ele é fácil de implementar e pode ser útil em situações onde a simplicidade e a eficiência para listas pequenas são importantes.

[↑ Algoritimos ↑](#mediana)

## Merge Sort - Dividir e conquistar
O **merge sort** (ou ordenação por mesclagem) é um algoritmo de ordenação eficiente e estável que segue o paradigma "dividir para conquistar". Ele divide repetidamente o array em subarrays menores até que cada subarray tenha apenas um elemento, e então mescla esses subarrays de forma ordenada para produzir o array final ordenado.

### Definição

O merge sort ordena um array de números dividindo-o em duas metades, ordenando cada metade recursivamente e, em seguida, mesclando as duas metades ordenadas para produzir um array ordenado.

### Passos do Algoritmo

1. **Divisão**:
   - Divida o array original em duas metades aproximadamente iguais.

2. **Recursão**:
   - Aplique merge sort recursivamente a cada metade até que cada subarray tenha apenas um elemento.

3. **Mesclagem**:
   - Mescle os subarrays ordenados para formar um array ordenado. A mesclagem é feita comparando os elementos dos subarrays e inserindo o menor elemento na posição correta no array final.

***Exemplo de implementação do merge sort em C++:***

```cpp
#include <iostream>
#include <vector>

// Função para mesclar dois subarrays ordenados
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria arrays temporários
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Mescla os arrays temporários de volta no array original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copia os elementos restantes de L, se houver
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copia os elementos restantes de R, se houver
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Função principal do merge sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Array ordenado: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Complexidade

- **Tempo**:
  - **Melhor caso**: O(n log n)
  - **Pior caso**: O(n log n)
  - **Caso médio**: O(n log n)
  - O merge sort é eficiente e tem a mesma complexidade de tempo em todos os casos, pois sempre divide o array em duas metades e mescla as metades ordenadas.

- **Espaço**: O(n) - O merge sort requer espaço adicional proporcional ao tamanho do array para armazenar os subarrays temporários durante a mesclagem.

### Resumo

O merge sort é um algoritmo de ordenação eficiente e estável que segue o paradigma "dividir para conquistar". Ele divide o array em subarrays menores, ordena cada subarray recursivamente e mescla os subarrays ordenados para produzir o array final ordenado. Com complexidade de tempo O(n log n) em todos os casos, o merge sort é uma escolha sólida para ordenar grandes conjuntos de dados, embora requeira espaço adicional para os subarrays temporários.

[↑ Algoritimos ↑](#mediana)

## Ford-Johnson Algorithm
O **algoritmo Ford-Johnson**, também conhecido como **algoritmo de ordenação por inserção de pares** ou **algoritmo de ordenação de merge-insert**, é um algoritmo de ordenação que visa minimizar o número de comparações necessárias para ordenar um conjunto de números. Ele é particularmente eficiente para conjuntos de dados pequenos a médios.

### Definição

O algoritmo Ford-Johnson é um algoritmo de ordenação que combina técnicas de inserção e mesclagem para ordenar um array de números. Ele é projetado para minimizar o número de comparações, o que o torna eficiente em termos de complexidade de comparação.

### Passos do Algoritmo

1. **Divisão Inicial**:
   - Divida o array original em pares de elementos.
   - Ordene cada par de elementos.

2. **Construção da Sequência Inicial**:
   - Construa uma sequência inicial de elementos ordenados a partir dos pares ordenados.

3. **Inserção de Elementos Restantes**:
   - Insira os elementos restantes na sequência inicial de forma ordenada, utilizando uma técnica de inserção eficiente.

4. **Mesclagem Final**:
   - Mescle as subsequências ordenadas para formar o array final ordenado.

***Exemplo de implementação simplificada do algoritmo Ford-Johnson em C++:***

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort e std::inplace_merge

void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void mergeInsertSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeInsertSort(arr, left, mid);
        mergeInsertSort(arr, mid + 1, right);
        std::inplace_merge(arr.begin() + left, arr.begin() + mid + 1, arr.begin() + right + 1);
    }
}

void fordJohnsonSort(std::vector<int>& arr) {
    int n = arr.size();
    int sublistSize = std::sqrt(n); // Tamanho das sublistas
    for (int i = 0; i < n; i += sublistSize) {
        insertionSort(arr, i, std::min(i + sublistSize - 1, n - 1));
    }
    mergeInsertSort(arr, 0, n - 1);
}

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    fordJohnsonSort(arr);

    std::cout << "Array ordenado: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Complexidade

- **Tempo**:
  - O algoritmo Ford-Johnson é projetado para minimizar o número de comparações, mas sua complexidade exata pode variar dependendo da implementação específica. Em geral, ele é eficiente para conjuntos de dados pequenos a médios.

- **Espaço**: O(n) - O algoritmo pode requerer espaço adicional para armazenar subarrays temporários durante a mesclagem.

### Resumo

O algoritmo Ford-Johnson é um algoritmo de ordenação eficiente que combina técnicas de inserção e mesclagem para minimizar o número de comparações necessárias para ordenar um array de números. Ele é particularmente útil para conjuntos de dados pequenos a médios e é projetado para ser eficiente em termos de complexidade de comparação.

[↑ Algoritimos ↑](#mediana)

</details>

### Referencias
- [wikipedia](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [stack overflow](https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort)
- [geeeksforgeeks](https://www.geeksforgeeks.org/sorting-by-combining-insertion-sort-and-merge-sort-algorithms/)
- [nerraou (github)](https://github.com/nerraou/Ford-Johnson-algorithm)
- [MIT (youtube)](https://www.youtube.com/watch?v=Kg4bqzAqRBM)
- [merge sort (youtube)](https://youtu.be/3j0SWDX4AtU?si=T84jCrEQO-c1nJdy)
- [insertion sort (youtube)](https://www.youtube.com/watch?v=8mJ-OhcfpYg)