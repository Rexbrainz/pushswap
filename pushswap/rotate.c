/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:33:45 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/10 08:49:06 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(struct s_stack *stack)
{
	struct s_node	*last;

	if (!stack->head || !stack->head->next)
		return ;
	last = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = last;
	last->prev = stack->tail;
	stack->tail = last;
	last->next = NULL;
}

void	ra(struct s_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(struct s_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(struct s_stack *a, struct s_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
