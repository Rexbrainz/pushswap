/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 07:20:16 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/03 13:35:49 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static bool	add_node(struct s_stack *a, int num);

void	init_stack_a(struct s_stack *a, int *valid_ints)
{
	int				i;
	bool			check_status;

	i = 0;
	while (i < a->size)
	{
		check_status = add_node(a, valid_ints[i++]);
		if (!check_status)
		{
			while (a->head->next)
			{
				a->head = a->head->next;
				free(a->head->prev);
			}
			free(a->head);
			error("Maloc failed.\n");
		}
	}
}

static bool	add_node(struct s_stack *a, int num)
{
	struct s_node	*new_node;

	new_node = (struct s_node *) malloc(sizeof(struct s_node));
	if (!new_node)
		return (false);
	new_node->value = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!a->head)
	{
		a->head = new_node;
		a->tail = new_node;
	}
	else
	{
		a->tail->next = new_node;
		new_node->prev = a->tail;
		a->tail = new_node;
	}
	return (true);
}

void	init_stacks(struct s_stack *a, struct s_stack *b)
{
	a->head = NULL;
	a->tail = NULL;
	a->size = 0;
	b->head = NULL;
	b->tail = NULL;
	b->size = 0;
}
