/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:40:26 by sudaniel          #+#    #+#             */
/*   Updated: 2024/11/30 08:20:45 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error(const char *error_message)
{
	ft_printf(error_message);
	exit(EXIT_FAILURE);
}

void	free_mem(char **mem_to_free)
{
	int	i;

	i = 0;
	while (mem_to_free[i])
		free(mem_to_free[i++]);
	free(mem_to_free);
}

void	free_and_exit(char **mem_to_free)
{
	free_mem(mem_to_free);
	error("Error\n");
}
