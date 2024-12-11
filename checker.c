/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:50 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/11 10:23:46 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap_both(struct s_stack *a, struct s_stack *b)
{
	swap(a);
	swap(b);
}

static void	rotate_both(struct s_stack *a, struct s_stack *b)
{
	rotate(a);
	rotate(b);
}

static void	reverse_rotate_both(struct s_stack *a, struct s_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

static int	compare_and_execute(struct s_stack *a, struct s_stack *b
		, const char *line)
{
	if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		push(a, b);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		push(b, a);
	else if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		swap(a);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		swap(b);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		swap_both(a, b);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		rotate(a);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rotate(b);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		reverse_rotate_both(a, b);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	struct s_stack	a;
	struct s_stack	b;
	char			*line;

	if (argc < 2)
		return (0);
	init_stacks(&a, &b);
	check_argv(&a, argv + 1);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!compare_and_execute(&a, &b, line))
			handle_checker_error(&a, &b);
		free(line);
	}
	if (is_sorted(&a) && !b.head)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	return (0);
}
