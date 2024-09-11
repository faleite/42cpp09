```
:::██████╗██████╗ ██████╗:::::██████╗::█████╗:::
::██╔════╝██╔══██╗██╔══██╗:::██╔═████╗██╔══██╗::
::██║:::::██████╔╝██████╔╝:::██║██╔██║╚█████╔╝::
::██║:::::██╔═══╝ ██╔═══╝::::████╔╝██║██╔══██╗::
::╚██████╗██║:::::██║::::::::╚██████╔╝╚█████╔╝::
:::╚═════╝╚═╝:::::╚═╝:::::::::╚═════╝::╚════╝:::
```

*This module is designed to help you understand\
templated containers, iterators and algorithms in CPP.*

 Skills | Grade |
:------:|:-----:|
[**Imperative programming**] [**Object-oriented programming**] [**Rigor**] | **Subscribed :atom:**
<!-- **:white_check_mark: 100%** -->

* **[Introduction](#introduction)**
  * **[General rules](#general-rules)**
  * **[design requirements](#alguns-requisitos-de-design)**
  * **[Read me](#read-me)**
  * **[Orthodox Canonical Form](#orthodox-canonical-form)**
* **[Module-specific rules](#module-specific-rules)**
* **[Wiki](https://github.com/faleite/42cpp00/wiki/)**
* **[Roadmap](https://faleite.github.io/cpp)**
* **[Study resources](#study-resources)**
<!-- * ### [Usage]() -->
<!-- * ### [Workflow](#workflow-1) -->
<!-- * ### [Tools](#tools-1) -->

## Introduction

- C++ é uma linguagem de programação de uso geral criada por Bjarne Stroustrup como uma extensão da linguagem de programação C, ou "C com Classes" [wikipedia](https://en.wikipedia.org/wiki/C++).
- O objetivo desses módulos é apresentar a **Programação Orientada a Objetos**. Este será o ponto de partida de sua jornada em C++. Muitas linguagens são recomendadas para aprender OOP. Decidimos escolher C++ porque ele é derivado do seu velho amigo C. Por ser uma linguagem complexa e para manter as coisas simples, seu código estará em conformidade com o padrão C++ 98. Estamos cientes de que o C++ moderno é muito diferente em muitos aspectos. Portanto, se você deseja se tornar um desenvolvedor C++ proficiente, cabe a você ir além após o 42 Common Core!

### General rules
- Compile seu código com: `c++ -Wall -Wextra -Werror -std=c++98`
- Formato **UpperCamelCase**: Arquivos contendo código de classe serão sempre nomeado de acordo com o nome da classe. Por exemplo: `ClassName.hpp/ClassName.h, ClassName.cpp ou ClassName.tpp`. Então, se você tem um arquivo de cabeçalho contendo a definição de uma classe "BrickWall" que representa um parede de tijolos, seu nome será BrickWall.hpp.
- A menos que especificado de outra forma, todas as mensagens de saída devem ser finalizadas com uma nova linha caractere e exibido na saída padrão.
- **Adeus Norminette!** Nenhum estilo de codificação é imposto nos módulos C++.
- Você tem permissão para usar quase tudo da biblioteca padrão.
- Você não pode usar nenhuma outra biblioteca externa. C++ 11 (e derivadas) e bibliotecas Boost são proibidas. As seguintes funções também são proibidas: **\* printf(), \* alloc() e free()**.
- A menos que seja explicitamente declarado o contrário, o uso de *namespace* `<ns_name>` e friend keywords amigo são proibidos.
- **É permitido utilizar o STL somente nos Módulos 08 e 09**. Isso significa: nenhum **Contêiner** (vector/list/map/ e assim por diante) e nenhum **algoritmo** (qualquer coisa que exija a inclusão do cabeçalho `<algorithm>`) até então.

### Alguns requisitos de design
- O vazamento de memória também ocorre em C++. Ao alocar memória (usando a palavra-chave **new**), você deve evitar **memory leaks**.
- Do Módulo 02 ao Módulo 09, suas classes deverão ser elaboradas na **Forma Canônica Ortodoxa**, ***exceto quando explicitamente indicado o contrário***.
- Qualquer implementação de função colocada em um arquivo de cabeçalho (exceto função template) significa 0 para o exercício.
- Você deve ser capaz de usar cada um dos seus cabeçalhos independentemente dos outros. Assim, eles devem incluir todas as dependências de que necessitam. No entanto, você deve evitar o problema de dupla inclusão adicionando **include guards** Caso contrário, sua nota será 0.

### Read me
- Você pode adicionar alguns arquivos adicionais se precisar (ou seja, para dividir seu código). Como essas atribuições não são verificadas por um programa, fique à vontade para fazê-lo, desde que entregue os arquivos obrigatórios.
- Às vezes, as diretrizes de um exercício parecem curtas, mas os exemplos podem mostrar requisitos que não estão explicitamente escritos nas instruções.
- Leia cada módulo completamente antes de começar! Realmente, faça isso.

> *Você terá que implementar muitas classes. Isso pode parecer tedioso, a menos que você consiga criar o script do seu editor de texto favorito.*

> Você tem uma certa liberdade para completar os exercícios. Porém, siga as regras obrigatórias e não seja preguiçoso. Você perderia muitas informações úteis! Não hesite em ler sobre conceitos teóricos.

###  Orthodox Canonical Form
- Todas as suas classes devem ser projetadas na Forma **Orthodox Canonical Form** (Forma Canônica Ortodoxa), a menos que explicitamente declarado o contrário. Então, elas implementarão as quatro funções de membro necessárias abaixo:
  - Construtor padrão
  - Construtor de cópia
  - Operador de atribuição de cópia
  - Destrutor

*Divida o código da sua classe em dois arquivos. O arquivo de cabeçalho (.hpp/.h) contém a definição da classe, enquanto o arquivo de origem (.cpp) contém a implementação.*

## Module-specific rules
- Você notará que, neste módulo, os exercícios podem ser resolvidos SEM os Containers padrão e SEM os Algoritmos padrão.

- No entanto, **usá-los é precisamente o objetivo deste Módulo**. Você tem permissão para usar o STL. Sim, você pode usar os **Containers** (vetor/lista/mapa/e assim por diante) e os **Algoritmos** (definidos no cabeçalho \<algoritmo\>). Além disso, você deve usá-los o máximo que puder. Portanto, faça o seu melhor para aplicá-los onde for apropriado.

- Você receberá uma nota muito ruim se não fizer isso, mesmo que seu código funcione como esperado. Por favor, não seja preguiçoso.

- Você pode definir seus modelos nos arquivos de cabeçalho como de costume. Ou, se quiser, pode escrever suas declarações de modelo nos arquivos de cabeçalho e escrever suas implementações em arquivos .tpp. Em qualquer caso, os arquivos de cabeçalho são obrigatórios, enquanto os arquivos .tpp são opcionais.

## Study resources
Resource | Source
---------|:-----:
[CPP Module 08](https://github.com/faleite/42cpp00/wiki/Module-IX) | `Wiki`
[CPP Tutorial (C++98)](https://cplusplus.com/doc/oldtutorial) | `Website`
[CPP Reference](https://cplusplus.com/) | `Website`
[CPP++ shell](http://cpp.sh) | `run code online`
[C++ Roadmap](https://roadmap.sh/cpp) | `roadmap.sh`
[Wiki 42cpp](https://github.com/qingqingqingli/CPP/wiki) | `GitHub`
[Os 4 Pilares da Orientação a Objetos](https://www.youtube.com/live/j2w8sMWhngo?si=eVnd-m_T-J3S8XpA) | `YouTube`
<!-- [Modules 00-04](https://github.com/pin3dev/42_CPP_Modules_00-04) | `GitHub` 
[piscine CPP](https://github.com/paulahemsi/piscine_cpp) | `GitHub` -->

