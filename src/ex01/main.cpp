/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:31:45 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/19 17:31:49 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
Você deve criar um programa com estas restrições:
- O nome do programa é RPN.
- Seu programa deve ter uma expressão matemática polonesa invertida como argumento.
- Os números usados ​​nesta operação e passados ​​como argumentos serão sempre menores 
que 10. O cálculo em si, mas também o resultado, não levam em conta esta regra.
- Seu programa deve processar esta expressão e gerar o resultado correto na saída padrão.
- Se ocorrer um erro durante a execução do programa, uma mensagem de erro 
deve ser exibida no erro padrão.
- Seu programa deve ser capaz de manipular operações com estes tokens: "+ - / *".

Você deve usar pelo menos um contêiner em seu código para validar este
exercício.

Você não precisa gerenciar os colchetes ou números decimais.
*/

int	main(int argc, char *argv[])
{
	if (argc != 2 || emptyWhitespace(argv[1]))
	{
		std::cerr << "Error: invalid expression" << std::endl;
        return (1);
	}
	
	try
	{
		RPN rpn;
		rpn.storeNumbers(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}