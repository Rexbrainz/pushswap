/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 06:18:06 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/13 13:51:43 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(struct s_stack *a)
{
	struct s_node	*max_node;

	max_node = a->head;
	if (a->head->value < a->head->next->value)
		max_node = a->head->next;
	if (max_node->value < a->tail->value)
		max_node = a->tail;
	if (max_node == a->head)
	{
		ra(a);
		if (!is_sorted(a))
			sa(a);
	}
	else if (max_node == a->head->next)
	{
		rra(a);
		if (!is_sorted(a))
			sa(a);
	}
	else
		if (!is_sorted(a))
			sa(a);
}

void	sort(struct s_stack *a, struct s_stack *b)
{
	if (a->size == 2 && !is_sorted(a))
		sa(a);
	else if (a->size == 3 && !is_sorted(a))
		sort_three(a);
	else if (a->size > 3 && !is_sorted(a))
		stack_sort(a, b);
}
