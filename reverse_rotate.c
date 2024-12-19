/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:44:31 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/10 08:50:03 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(struct s_stack *stack)
{
	struct s_node	*first;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	first->next = stack->head;
	stack->head->prev = first;
	first->prev = NULL;
	stack->head = first;
}

void	rra(struct s_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(struct s_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(struct s_stack *a, struct s_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
