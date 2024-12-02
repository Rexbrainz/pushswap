/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:21:06 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/02 18:32:17 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	check_leaks(void)
{
	system("leaks push_swap");
}

static void	free_joined(char *joined_str)
{
	free(joined_str);
	error("Malloc failed.\n");
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

	if (*ints == '-' || *ints == '+')
		ints++;
	i = 0;
	while (ints[i])
	{
		if (ints[i] >= '0' && ints[i] <= '9')
		{
			i++;
			continue ;
		}
		return (false);
	}
	if (i > 0)
	{
		num = ft_atol(ints);
		if (num > INT_MAX || num < INT_MIN)
			return (false);
		return (true);
	}
	return (false);
}

static struct s_stack	*check_argv(struct s_stack_info *l_info, char **argv)
{
	int					j;
	int					*valid_ints;
	char				**ints;
	char				*joined_args;
	struct s_stack		*a;

	joined_args = build_up_args(argv);
	if (!joined_args)
		error("Malloc failed.\n");
	ints = ft_split(joined_args, ' ');
	if (!ints)
		free_joined(joined_args);
	j = 0;
	while (ints[j])
		if (!check_str(ints[j++]))
			free_and_exit(ints);
	free_mem(ints);
	valid_ints = check_duplicates(joined_args, l_info);
	if (!valid_ints)
		free_joined(joined_args);
	a = init_stack_a(l_info, valid_ints);
	free(valid_ints);
	free(joined_args);
	return (a);
}

int	main(int argc, char **argv)
{
	struct s_stack_info	l_info;
	struct s_stack		*a;
	struct s_stack		*b;

	if (argc < 2)
		return (0);
	atexit(check_leaks);
	a = check_argv(&l_info, argv + 1);
	pb(&b, &a);
	pb(&b, &a);
	while (a->next)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
		if (a)
			free(a->prev);
	}
	ft_printf("%d\n", a->value);
	free(a);
	struct s_stack *curr = b;
	while (b)
	{
		ft_printf("stack_b-> %d\n", b->value);
		curr = b;
		b = b->next;
		if (b)
			free(b->prev);
	}
	free(curr);
	return (0);
}
