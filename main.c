/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:21:06 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/09 17:04:44 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>
/*
void	check_leaks(void)
{
	system("leaks push_swap");
}
*/
static void	free_joined(char *joined_str)
{
	free(joined_str);
	error("Error\n");
}

static char	*build_up_args(char **argv)
{
	char	*temp;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (argv[i])
		len += ft_strlen(argv[i++]);
	temp = (char *) malloc(len + i);
	if (!temp)
		return (NULL);
	i = 0;
	len = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			temp[len++] = argv[i][j++];
		if (argv[++i])
			temp[len++] = ' ';
	}
	temp[len] = '\0';
	return (temp);
}

static bool	check_str(char *ints)
{
	long	num;
	int		i;

	i = 0;
	if (ints[i] == '-' || ints[i] == '+')
		i++;
	if (!ints[i])
		return (false);
	while (ints[i])
	{
		if (ints[i] >= '0' && ints[i] <= '9')
		{
			i++;
			continue ;
		}
		return (false);
	}
	num = ft_atol(ints);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}

static void	check_argv(struct s_stack *a, char **argv)
{
	int					j;
	int					*valid_ints;
	char				**ints;
	char				*joined_args;

	joined_args = build_up_args(argv);
	if (!joined_args || !*joined_args)
		free_joined(joined_args);
	ints = ft_split(joined_args, ' ');
	if (!ints)
		free_joined(joined_args);
	j = 0;
	while (ints[j])
		if (!check_str(ints[j++]))
			free_and_exit(ints);
	free_mem(ints);
	valid_ints = check_duplicates(joined_args, a);
	if (!valid_ints)
		free_joined(joined_args);
	init_stack_a(a, valid_ints);
	free(valid_ints);
	free(joined_args);
}

int	main(int argc, char **argv)
{
	struct s_stack	a;
	struct s_stack	b;

	if (argc < 2)
		return (0);
	init_stacks(&a, &b);
	check_argv(&a, argv + 1);
	sort(&a, &b);
	free_stack(&a);
	return (0);
}
