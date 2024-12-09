/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_but_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:30:30 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/09 06:16:51 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_all_but_three(struct s_stack *a, struct s_stack *b)
{
	int				pushed;
	int				i;

	pushed = 0;
	i = 0;
	if (a->size > 6)
	{
		while (i < a->size && pushed < a->size / 2)
		{
			if (a->head->index <= a->size / 2)
			{
				pb(b, a);
				pushed++;
			}
			else
				ra(a);
			i++;
		}
	}
	while (a->size - pushed++ > 3)
		pb(b, a);
}
