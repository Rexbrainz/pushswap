/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:00:05 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/03 12:56:35 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(struct s_stack *dst, struct s_stack *src)
{
	struct s_node	*temp;

	if (!src->head)
		return ;
	temp = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	if (!dst->head)
	{
		dst->head = temp;
		dst->tail = temp;
	}
	else
	{
		temp->next = dst->head;
		dst->head->prev = temp;
		dst->head = temp;
	}
}

void	pa(struct s_stack *a, struct s_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(struct s_stack *b, struct s_stack *a)
{
	push(b, a);
	ft_printf("pb\n");
}
