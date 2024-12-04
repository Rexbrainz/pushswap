/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:42:35 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/04 06:58:57 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
};

struct s_stack
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
};

//	error:	Takes an error message, prints it and exits the program.
void	error(const char *error_message);

//	free_mem:	Frees the memory to free and exits the program.
void	free_mem(char **mem_to_free);

//	free_and_exit:	Takes memory to free, frees it, prints a message to the
//					console and exits the program.
void	free_and_exit(char **mem_to_free);

//	check_duplicates:	Conversts the string passed to it to array of ints
//						 and checks if any of the numbers are duplicates. 
//						 If so, returns an error message and exits the program,
//						 else returns the array of int.
int		*check_duplicates(const char *str, struct s_stack *a);

//	check_consecutive_spaces:	Checks all arguments for embedded spaces in them
//								prints and error message when found and exits
//								the program.
void	check_consecutive_spaces(char **argv);

//	init_stacks:	Takes two stacks and initializes them.
void	init_stacks(struct s_stack *a, struct s_stack *b);

//	Init_list:	Initializes a linked list after confirming the arguments are
//				valid.
void	init_stack_a(struct s_stack *a, int *valid_ints);

//	pa:	Takes two stacks and pushes the top of b to the top of a.
//		It returns nothing.
void	pa(struct s_stack *a, struct s_stack *b);

//	pb:	Takes two stacks and pushes the top of a to the top of b.
//		It returns nothing.
void	pb(struct s_stack *b, struct s_stack *a);

//	sa:	Takes a stack and and a bool flag, swaps its first two elements, 
//		if there is one or less it does nothing.
void	sa(struct s_stack *a);

//	sb:	Takes a stack and a bool flag,  swaps its first two elements,
//		 if there is one or less it does nothing.
void	sb(struct s_stack *b);

//	ss:	Takes two stacks, and swaps the first two element in each of the stacks
//		If there is one or less in any of them, it does nothing for the stack
//		with one or less elements in it.
void	ss(struct s_stack *a, struct s_stack *b);

//	ra:	Takes stack a, shifts all its element up by one and makes the first 
//		element become the last.
void	ra(struct s_stack *a);

//	rb:	Takes stack b, shifts all its element up by one and makes the first 
//		element become the last.
void	rb(struct s_stack *b);

//	rr:	Performs ra and rb at the same time.
void	rr(struct s_stack *a, struct s_stack *b);

//	ra:	Takes stack a, shifts all its element down by one and makes the last 
//		element become the first.
void	rra(struct s_stack *a);

//	rrb:	Takes stack b, shifts all its element down by one and makes the last
//		element become the first.
void	rrb(struct s_stack *b);

//	rrr:	Performs rra and rrb at the same time.
void	rrr(struct s_stack *a, struct s_stack *b);

#endif
