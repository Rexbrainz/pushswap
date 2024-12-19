/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:03:10 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/09 17:06:07 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	assign_cost(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*top;

	top = a->head;
	while (top)
	{
		if (top->pos > a->new_size / 2)
			top->cost = a->new_size - top->pos;
		else
			top->cost = top->pos;
		top = top->next;
	}
	top = b->head;
	while (top)
	{
		if (top->pos > b->new_size / 2)
			top->cost = b->new_size - top->pos;
		else
			top->cost = top->pos;
		top = top->next;
	}
}

void	find_cheapest_move(struct s_stack *a, struct s_stack *b)
{
	int				cheapest;
	struct s_node	*top;

	assign_cost(a, b);
	top = b->head;
	cheapest = b->head->cost + b->head->target_node->cost;
	b->best_move_node = b->head;
	top = b->head->next;
	while (top)
	{
		if (cheapest > top->cost + top->target_node->cost)
		{
			cheapest = top->cost + top->target_node->cost;
			b->best_move_node = top;
		}
		top = top->next;
	}
}
