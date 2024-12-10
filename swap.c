/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 06:30:27 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/10 08:43:04 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(struct s_stack *stack)
{
	struct s_node	*first;
	struct s_node	*third;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	stack->head = stack->head->next;
	third = stack->head->next;
	first->next = third;
	if (third)
		third->prev = first;
	first->prev = stack->head;
	stack->head->next = first;
	stack->head->prev = NULL;
}

void	sa(struct s_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(struct s_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(struct s_stack *a, struct s_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
