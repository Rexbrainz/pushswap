/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:55:25 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/04 08:00:44 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	free_ints(int *ints)
{
	free(ints);
	error("Error\n");
}

void	check_consecutive_spaces(char **argv)
{
	int	j;
	int	i;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			if (argv[i][j++] == ' ' && argv[i][j] == ' ')
				error("Error\n");
		i++;
	}
}

static bool	is_dup(int *ints, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
			if (ints[i] == ints[j++])
				return (true);
		i++;
	}
	return (false);
}

int	*check_duplicates(const char *str, struct s_stack *a)
{
	char	**char_nums;
	int		i;
	int		*ints;

	char_nums = ft_split(str, ' ');
	if (!char_nums)
		return ((int *) NULL);
	i = 0;
	while (char_nums[i])
		i++;
	ints = (int *) malloc(i * sizeof(int));
	if (!ints)
		return ((int *) NULL);
	i = 0;
	while (char_nums[i])
	{
		ints[i] = ft_atoi(char_nums[i]);
		free(char_nums[i++]);
	}
	free(char_nums);
	if (is_dup(ints, i))
		free_ints(ints);
	a->size = i;
	return (ints);
}
