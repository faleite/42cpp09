# C++
***(Modulo 08)***

## Index

01. **[Containers]()**
02. **[vector](#stdvector-sequence-container)**
03. **[list](#stdlist-sequence-container)**
04. **[stack](#stdstack-adapter-container)**
05. **[map](#stdmap-associative-container)**
06. **[iterators](#iterators)**
07. **[Resources](#resources)**

## std::vector (Sequence Container)
- **`std::vector`** é um contêiner de sequência que é dinamicamente redimensionável.
- vetores são muito eficientes acessando seus elementos (assim como arrays) e relativamente eficientes adicionando ou removendo elementos de seu `end`. 
- Para operações que envolvem inserir ou remover elementos em posições diferentes do `end`, eles têm desempenho pior que os outros, e têm iteradores e referências menos consistentes que lists e forward_lists.
- O contêiner usa um objeto alocador para manipular dinamicamente suas necessidades de armazenamento.
- `std::vector` Uso recomendado:
  - inserção/remoção de elementos no final da sequência.
  - acesso direto a elementos por sua posição.
  - iteração sobre os elementos em ordem sequencial.
  - acesso direto a elementos por meio de aritmética de ponteiros.
  - Ordenação rápida. (?)
- `std::vector` Uso não recomendado:
  - inserção/remoção de elementos em qualquer lugar que não seja no final da sequência.
  - classificação de elementos.
  - algoritmos que manipulam elementos em qualquer lugar que não seja no final da sequência.
- [leia mais](https://cplusplus.com/reference/vector/vector/)

[↑ Index ↑](#index)

## std::list (Sequence Container)
- **`std::list`** é um contêiner de sequência que é dinamicamente redimensionável.
- Listas são contêineres de sequência que permitem operações de inserção e exclusão de tempo constante em qualquer lugar dentro da sequência e iteração em ambas as direções.
- contêineres de lista são implementados como listas duplamente vinculadas; Listas duplamente vinculadas podem armazenar cada um dos elementos que contêm em locais de armazenamento diferentes e não relacionados. A ordenação é mantida internamente pela associação a cada elemento de um link para o elemento que o precede e um link para o elemento que o segue.
- Comparados a outros contêineres de sequência padrão básicos (`array` , `vector` e `deque`), as listas geralmente têm melhor desempenho na inserção, extração e movimentação de elementos em qualquer posição dentro do contêiner para o qual um iterador já foi obtido e, portanto, também em algoritmos que fazem uso intensivo deles, como algoritmos de classificação.
- A principal desvantagem de **list** em comparação a esses outros contêineres de sequência é que eles não têm acesso direto aos elementos por sua posição; Por exemplo, para acessar o sexto elemento em uma lista , é preciso iterar de uma posição conhecida (como o começo ou o fim) para essa posição, o que leva tempo linear na distância entre elas. Eles também consomem alguma memória extra para manter as informações de ligação associadas a cada elemento (o que pode ser um fator importante para grandes listas de elementos de tamanho pequeno).
- Cada elemento mantém informações sobre como localizar o próximo e o anterior elemento, permitindo operações de inserção e exclusão em tempo constante antes ou depois de um elemento específico (mesmo de intervalos inteiros), mas sem acesso aleatório direto (`Doubly-linked list`).
- O contêiner usa um objeto alocador para manipular dinamicamente suas necessidades de armazenamento.
- `std::list` Uso recomendado:
  - inserção/remoção de elementos em qualquer lugar dentro da sequência.
  - classificação de elementos.
  - algoritmos que manipulam elementos em qualquer lugar dentro da sequência.
- `std::list` Uso não recomendado:
  - acesso direto a elementos por sua posição.
  - iteração sobre os elementos em ordem sequencial.
  - acesso direto a elementos por meio de aritmética de ponteiros.
- [leia mais](https://cplusplus.com/reference/list/list/)

[↑ Index ↑](#index)

## std::stack (Adapter Container)
- Stacks são um tipo de adaptador de contêiner, projetados especificamente para operar em um contexto LIFO (last-in first-out), onde os elementos são inseridos e extraídos apenas de uma extremidade do contêiner.
- `stack`s são implementados como **adaptadores de contêiner**, que são classes que usam um objeto encapsulado de uma classe de contêiner específica como seu **contêiner subjacente**, fornecendo um conjunto específico de funções de membro para acessar seus elementos. Os elementos são ***empurrados/retirados*** (pushed/poped) da "***parte de trás***" (back) do contêiner específico, que é conhecido como o topo da pilha.
- O contêiner subjacente pode ser qualquer um dos modelos de classe de contêiner padrão ou alguma outra classe de contêiner projetada especificamente. O contêiner deve suportar as seguintes operações: `empty`, `size`, `back`, `push_back`, `pop_back`.
- As classes de contêiner padrão `vetor`, `deque` e `list` atende a esses requisitos. Por padrão, se nenhuma classe de contêiner for especificada para uma determinada instanciação de classe `stack`, o contêiner padrão `deque` é usado.
- `std::stack` Uso recomendado:
  - inserção/remoção de elementos no final da sequência.
- `std::stack` Uso não recomendado:
  - inserção/remoção de elementos em qualquer lugar que não seja no final da sequência.
  - classificação de elementos.
  - algoritmos que manipulam elementos em qualquer lugar que não seja no final da sequência.
- [leia mais](https://cplusplus.com/reference/stack/stack/)

[↑ Index ↑](#index)

### std::map (Associative Container)
- Mapas são contêineres associativos que armazenam elementos formados por uma combinação de um valor-chave e um valor mapeado , seguindo uma ordem específica.
- Em um mapa , os `valores-chave` são geralmente usados ​​para classificar e identificar exclusivamente os elementos, enquanto os `valores mapeados` armazenam o conteúdo associado a essa `chave`. Os tipos de `chave` e `valor mapeado` podem diferir e são agrupados no tipo de membro `value_type` , que é um tipo de par que combina ambos: `typedef pair<const Key, T> value_type;`.
- Internamente, os elementos em um mapa são sempre classificados por sua `chave` seguindo um critério de` ordenação fraco estrito` específico indicado por seu objeto de comparação interno (do tipo `Compare`).
- Os contêineres de mapa são geralmente mais lentos do que os contêineres `unordered_map` para acessar elementos individuais por sua `chave`, mas permitem a iteração direta em subconjuntos com base em sua ordem.
- Os valores mapeados em um `map` podem ser acessados ​​diretamente por sua chave correspondente usando o `operador de colchete` (`operator[]`).
- Os mapas são normalmente implementados como `árvores de busca binárias`.
- Elementos em contêineres **associativos** são referenciados por sua `chave` e não por sua posição absoluta no contêiner.
- Os elementos no contêiner seguem uma ordem (Ordenado) estrita o tempo todo. Todos os elementos inseridos recebem uma posição nessa ordem.
- Nenhum dos dois elementos no contêiner pode ter `chaves` equivalentes (**Chaves únicas**).
- `std::map` Uso recomendado:
  - acesso direto a elementos por sua chave.
  - iteração sobre os elementos em ordem sequencial.
  - classificação de elementos.
- [leia mais](https://cplusplus.com/reference/map/map/)

[↑ Index ↑](#index)

## iterators
- Um iterador é um objeto projetado para atravessar um contêiner, fornecendo acesso a cada elemento ao longo do caminho. Um contêiner pode fornecer diferentes tipos de iteradores.
- Uma vez que o tipo apropriado de iterador é criado, o programador pode então usar a interface fornecida pelo iterador para percorrer e acessar elementos sem ter que se preocupar com que tipo de travessia está sendo feita ou como os dados estão sendo armazenados no contêiner. E como os iteradores C++ normalmente usam a mesma interface para travessia ( operator++ to move to the next element) e acesso ( operator* to access the current element), podemos iterar por uma ampla variedade de diferentes tipos de contêiner usando um método consistente.
- Iteradores nos permitem visualizar uma coleção não linear de forma linear. O objetivo dos iteradores era ter uma interface padrão para iterar sobre dados em qualquer contêiner . Mas ainda tínhamos que especificar para qual tipo de dado esse iterador estava apontando.
- Qualquer tipo que satisfaça sua interface implícita é válido para uso com uma função modelada.
- Cada coleção diferente vem equipada com seu próprio tipo de iterador. Queremos, em última análise, escrever funções genéricas para trabalhar com iteradores sobre qualquer sequência. Com modelos, podemos!

*Exemplo*
```cpp
vector<int> v;
vector<int>::iterator itr = v.begin();

vector<double> v;
vector<double>::iterator itr = v.begin();

deque<int> d;
deque<int>::iterator itr = d.begin();
```

[↑ Index ↑](#index)

## Resources
Resource | Source
---------|:-----:
[Containers](https://cplusplus.com/reference/stl/) | `Site`
[\<algorithm\>](https://cplusplus.com/reference/algorithm/) | `Site`
[Most useful C++ STL algorithms](https://www.geeksforgeeks.org/c-magicians-stl-algorithms/) | `Site`
[Templates tutorial](https://cplusplus.com/doc/oldtutorial/templates/) | `Site`
[Exception handling](https://cplusplus.com/reference/stdexcept/) | `Site`
[deque](https://cplusplus.com/reference/deque/deque/) | `Site`