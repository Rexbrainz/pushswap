/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_but_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:30:30 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/07 18:44:40 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_all_but_three(struct s_stack *a, struct s_stack *b)
{
	int				pushed;
	int				i;

	pushed = 0;
	i = 0;
	if (a->size > 99)
	{
		while (i < a->size && pushed < a->size / 4)
		{
			if (a->head->index <= a->size / 4)
			{
				pb(b, a);
				pushed++;
			}
			else
				ra(a);
			i++;
		}
	}
	if (a->size - pushed > 3)
		while (a->size - pushed++ > 3)
			pb(b, a);
}
