# C++
***Modulo 09 - ex01***

## Workflow
<details>
  <summary>Desenvolvimento</summary>

### Etapas Iniciais para o Desenvolvimento do Projeto

1. **Definição do Algoritmo Merge-Insert Sort:**
   - [ ] Pesquise e entenda o algoritmo Ford-Johnson (merge-insert sort).
   - [ ] Planeje a implementação do algoritmo para dois contêineres diferentes (por exemplo, `std::vector` e `std::list`).

2. **Planejamento das Funções Principais:**
   - [ ] Função para leitura e validação dos argumentos de entrada.
   - [ ] Função para exibir a sequência de inteiros não classificados.
   - [ ] Função para aplicar o algoritmo de ordenação usando o primeiro contêiner.
   - [ ] Função para aplicar o algoritmo de ordenação usando o segundo contêiner.
   - [ ] Função para medir e exibir o tempo de execução de cada contêiner.
   - [ ] Função para tratamento de erros e exibição de mensagens de erro.

3. **Especificação dos Arquivos de Cabeçalho:**
   - [ ] Defina as classes e funções no arquivo `PmergeMe.hpp`:
     ```cpp
     #ifndef PMERGEME_HPP
     #define PMERGEME_HPP

     #include <vector>
     #include <list>
     #include <string>

     class PmergeMe {
     public:
         PmergeMe();
         ~PmergeMe();

         void readInput(int argc, char* argv[]);
         void displayUnsortedSequence() const;
         void sortUsingVector();
         void sortUsingList();
         void displaySortedSequence() const;
         void displayExecutionTime() const;

     private:
         std::vector<int> vectorSequence;
         std::list<int> listSequence;
         std::string unsortedSequence;
         std::string sortedSequence;
         double vectorSortTime;
         double listSortTime;

         void mergeInsertSortVector(std::vector<int>& sequence);
         void mergeInsertSortList(std::list<int>& sequence);
     };

     #endif // PMERGEME_HPP
     ```

4. **Implementação do Arquivo Principal:**
   - [ ] Estruture o arquivo `main.cpp` para inicializar o programa e chamar as funções principais:
     ```cpp
     #include "PmergeMe.hpp"
     #include <iostream>

     int main(int argc, char* argv[]) {
         try {
             PmergeMe pmergeMe;
             pmergeMe.readInput(argc, argv);
             pmergeMe.displayUnsortedSequence();
             pmergeMe.sortUsingVector();
             pmergeMe.sortUsingList();
             pmergeMe.displaySortedSequence();
             pmergeMe.displayExecutionTime();
         } catch (const std::exception& e) {
             std::cerr << "Erro: " << e.what() << std::endl;
             return 1;
         }
         return 0;
     }
     ```

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
  <summary>Utils</summary>

```cpp

```

</details>

### Referencias
- [wikipedia](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [stack overflow](https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort)
- [geeeksforgeeks](https://www.geeksforgeeks.org/sorting-by-combining-insertion-sort-and-merge-sort-algorithms/)
- [nerraou (github)](https://github.com/nerraou/Ford-Johnson-algorithm)
- [MIT (youtube)](https://www.youtube.com/watch?v=Kg4bqzAqRBM)