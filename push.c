/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:00:05 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/02 18:23:39 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(struct s_stack **dst, struct s_stack **src)
{
	struct s_stack	*temp;

	temp = *src;
	*src = (*src)->next;
	(*src)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	if (!*dst)
		*dst = temp;
	else
	{
		temp->next = *dst;
		(*dst)->prev = temp;
		*dst = temp;
	}
}

void	pa(struct s_stack **a, struct s_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(struct s_stack **b, struct s_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}
