/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 08:18:42 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/06 20:27:15 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_sort(struct s_stack *a, struct s_stack *b);

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

	top = a_head;
	min_index = top->index;
	min_index_node = top;
	while (top)
	{
		if (top->next)
		{
			if (min_index > top->next->index)
			{
				min_index = top->next->index;
				min_index_node = top->next;
			}
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
		smallest_bigger = a->new_size + 1;
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
		ft_printf("top_b index is %d and top->b target node: %d\n", top_b->index, top_b->target_node->index);
		top_b = top_b->next;
	}
}

/*
int main(int argc, char **argv)
{
	struct s_stack	a;
	struct s_stack	b;
	struct s_node	*new_node;
	int				num;
	int				i;

	if (argc > 20)
		return (0);
	a.head = NULL;
	b.head = NULL;
	i = 1;
	a.size = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i++]);
		new_node = malloc(sizeof(struct s_node));
		new_node->value = num;
		new_node->index = 0;
		new_node->next = NULL;
		if (a.head)
		{
			new_node->next = a.head;
			a.head = new_node;
		}
		else if (!a.head)
			a.head = new_node;
		a.size++;
	}
	assign_index(&a);
	stack_sort(&a, &b);
	while (a.head)
	{
		ft_printf("num: %d and index: %d\n", a.head->value, a.head->index);
		a.head = a.head->next;
	}
	while (b.head)
	{
		ft_printf("num: %d and index: %d\n", b.head->value, a.head->index);
		b.head = b.head->next;
	}


}


static void	push_all_but_three(struct s_stack *a, struct s_stack *b)
{
	struct s_stack	*top;

	top = a->head;
	while (
}
*/

void	stack_sort(struct s_stack *a, struct s_stack *b)
{
	int	size;

	a->new_size = a->size;
	b->new_size = b->size;
	assign_index(a);
	size = 0;
	while (size++ < a->size - 3)
		pb(b, a);
	sort_three(a);
	assign_pos(a, b);
	assign_targets(a, b);
	find_best_move(a, b);
}
