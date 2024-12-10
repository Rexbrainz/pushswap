/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:04:32 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/10 08:04:47 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
	Check leaks:
		1. dorker make re 
		2. dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
	
	If you modify code, do 1 again.
*/
int	main(int argc, char **argv)
{
	struct s_stack	a;
	struct s_stack	b;

	if (argc < 2)
		return (0);
	init_stacks(&a, &b);
	check_argv(&a, argv + 1);
	sort(&a, &b);
	free_stack(&a);
	return (0);
}
