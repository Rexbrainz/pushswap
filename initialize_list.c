/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 07:20:16 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/02 16:54:41 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static bool	add_node(struct s_stack_info *l_info, struct s_stack **a, int num);

struct s_stack	*init_stack_a(struct s_stack_info *l_info, int *valid_ints)
{
	int				i;
	bool			check_status;
	struct s_stack	*list;

	list = NULL;
	i = 0;
	while (i < l_info->size)
	{
		check_status = add_node(l_info, &list, valid_ints[i++]);
		if (!check_status)
		{
			while (list->next)
			{
				list = list->next;
				free(list->prev);
			}
			free(list);
			error("Maloc failed.\n");
		}
	}
	l_info->head = list;
	return (list);
}

static bool	add_node(struct s_stack_info *l_info, struct s_stack **a, int num)
{
	struct s_stack	*new_node;
	struct s_stack	*last_node;

	new_node = (struct s_stack *) malloc(sizeof(struct s_stack));
	if (!new_node)
		return (false);
	new_node->value = num;
	if (*a == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*a = new_node;
	}
	else
	{
		last_node = *a;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
		new_node->next = NULL;
	}
	l_info->tail = new_node;
	return (true);
}
/*
static void	add_to_head(struct s_dlist **list, struct s_dlist *new_node)
{
	if (*list == NULL)
		*list = new_node;
	else
	{
		new_node->next = *list;
		*list = new_node;
	}
}

static void	add_to_tail(struct s_dlist **list, struct s_dlist *new_node)
{
	struct s_dlist	*curr;

	if (*list == NULL)
		*list = new_node;
	else
	{
		curr = *list;
		while (curr->next)
			curr = curr->next;
		new_node->prev = curr;
		curr->next = new_node;
	}
}
*/
