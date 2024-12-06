/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:41:29 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/06 18:51:55 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rev_rot(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*b_move;

	b_move = b->head;
	if (b_move->cost)
	{
		while (b_move->cost)
		{
			rrb(b);
			b_move->cost--;
		}
	}
	else if (b_move->target_node->cost)
	{
		while (b_move->target_node->cost)
		{
			rra(a);
			b_move->target_node->cost--;
		}
	}
}

void	execute_rrr(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*b_move;

	b_move = b->head;
	while (b_move->cost && b_move->target_node->cost)
	{
		rrr(a, b);
		b_move->cost--;
		b_move->target_node->cost--;
	}
	rev_rot(a, b);
	pa(a, b);
}
