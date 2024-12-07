/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 08:18:42 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/07 17:07:18 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	assign_index(struct s_stack *a)
{
	int				size;
	struct s_node	*top;
	struct s_node	*max_node;

	size = a->size;
	while (size--)
	{
		top = a->head;
		max_node = top;
		while (top)
		{
			if (top->next)
			{
				if (max_node->index > 0)
					max_node = top->next;
				if (max_node->value < top->next->value && top->next->index == 0)
					max_node = top->next;
			}
			top = top->next;
		}
		max_node->index = size + 1;
	}
}

static void	assign_pos(struct s_stack *a, struct s_stack *b)
{
	int				pos;
	struct s_node	*top_a;
	struct s_node	*top_b;

	top_a = a->head;
	top_b = b->head;
	pos = 0;
	while (top_a)
	{
		top_a->pos = pos++;
		top_a = top_a->next;
	}
	pos = 0;
	while (top_b)
	{
		top_b->pos = pos++;
		top_b = top_b->next;
	}
}

static struct s_node	*find_min_index(struct s_node *a_head)
{
	int				min_index;
	struct s_node	*top;
	struct s_node	*min_index_node;

	min_index = a_head->index;
	min_index_node = a_head;
	top = a_head->next;
	while (top)
	{
		if (min_index > top->index)
		{
			min_index = top->index;
			min_index_node = top;
		}
		top = top->next;
	}
	return (min_index_node);
}

static void	assign_targets(struct s_stack *a, struct s_stack *b)
{
	int				smallest_bigger;
	struct s_node	*min_index;
	struct s_node	*top_a;
	struct s_node	*top_b;

	top_b = b->head;
	min_index = find_min_index(a->head);
	while (top_b)
	{
		top_a = a->head;
		top_b->target_node = NULL;
		smallest_bigger = INT_MAX;
		while (top_a)
		{
			if (top_a->index > top_b->index && top_a->index < smallest_bigger)
			{
				smallest_bigger = top_a->index;
				top_b->target_node = top_a;
			}
			top_a = top_a->next;
		}
		if (!top_b->target_node)
			top_b->target_node = min_index;
		top_b = top_b->next;
	}
}

void	stack_sort(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*min_index;

	a->new_size = a->size;
	b->new_size = b->size;
	assign_index(a);
	push_all_but_three(a, b);
	sort_three(a);
	while (b->head)
	{
		assign_pos(a, b);
		assign_targets(a, b);
		find_best_move(a, b);
		execute_moves(a, b);
	}
	if (!is_sorted(a))
	{
		min_index = find_min_index(a->head);
		assign_pos(a, b);
		if (min_index->pos > a->size / 2)
		{
			while (a->size - min_index->pos++ > 0)
				rra(a);
		}
		else
			while (min_index->pos--)
				ra(a);
	}
}
