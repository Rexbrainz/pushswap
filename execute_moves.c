/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:41:29 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/07 16:38:05 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*
static void	rev_rot(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*b_move;

	b_move = b->head;
	if (b_move->cost)
		while (b_move->cost--)
			rrb(b);
	else if (b_move->target_node->cost)
		while (b_move->target_node->cost--)
			rra(a);
}
*/
static void	execute_rrr(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*b_move;

	b_move = b->best_move_node;
	while (b_move->cost && b_move->target_node->cost)
	{
		rrr(a, b);
		b_move->cost--;
		b_move->target_node->cost--;
	}
	if (b_move->cost)
		while (b_move->cost--)
			rrb(b);
	else if (b_move->target_node->cost)
		while (b_move->target_node->cost--)
			rra(a);
}

static void	execute_rr(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*b_move;

	b_move = b->best_move_node;
	while (b_move->cost && b_move->target_node->cost)
	{
		rr(a, b);
		b_move->cost--;
		b_move->target_node->cost--;
	}
	if (b_move->cost)
		while (b_move->cost--)
			rb(b);
	else if (b_move->target_node->cost)
		while (b_move->target_node->cost--)
			ra(a);
}

static void	execute_rev_or_rot(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*b_move;

	b_move = b->head;
	if (b_move->target_node->pos > a->new_size / 2)
		while (b_move->target_node->cost--)
			rra(a);
	else
		while (b_move->target_node->cost--)
			ra(a);
	if (b_move->pos > b->new_size / 2)
		while (b_move->cost--)
			rrb(b);
	else
		while (b_move->cost--)
			rb(b);
}

void	execute_moves(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*b_move;

	b_move = b->best_move_node;
	if (b_move->pos > b->new_size / 2
		&& b_move->target_node->pos > a->new_size / 2)
	{
		execute_rrr(a, b);
		pa(a, b);
	}
	else if (b_move->pos <= b->new_size / 2
		&& b_move->target_node->pos <= a->new_size / 2)
	{
		execute_rr(a, b);
		pa(a, b);
	}
	else
	{
		execute_rev_or_rot(a, b);
		pa(a, b);
	}
}
