/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:44:30 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/06 18:49:52 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rot(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*b_move;

	b_move = b->head;
	if (b_move->cost)
	{
		while (b_move->cost)
		{
			rb(b);
			b_move->cost--;
		}
	}
	else if (b_move->target_node->cost)
	{
		while (b_move->target_node->cost)
		{
			ra(a);
			b_move->target_node->cost--;
		}
	}
}

void	execute_rr(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*b_move;

	b_move = b->head;
	while (b_move->cost && b_move->target_node->cost)
	{
		rr(a, b);
		b_move->cost--;
		b_move->target_node->cost--;
	}
	rot(a, b);
	pa(a, b);
}
