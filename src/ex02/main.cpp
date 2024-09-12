/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:35:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/12 19:40:32 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
*/