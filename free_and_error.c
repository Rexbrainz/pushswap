/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:40:26 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/11 09:43:32 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error(const char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	exit(EXIT_FAILURE);
}

void	free_mem(char **mem_to_free)
{
	int	i;

	i = 0;
	while (mem_to_free[i])
		free(mem_to_free[i++]);
	free(mem_to_free);
}

void	free_and_exit(char **mem_to_free, char *str)
{
	free(str);
	free_mem(mem_to_free);
	error("Error\n");
}

void	free_stack(struct s_stack *a)
{
	struct s_node	*prev;

	prev = a->head;
	while (a->head)
	{
		prev = a->head;
		a->head = a->head->next;
		if (a->head)
			free(a->head->prev);
	}
	free(prev);
}

void	handle_checker_error(struct s_stack *a, struct s_stack *b)
{
	free_stack(a);
	free_stack(b);
	error("Error\n");
}
