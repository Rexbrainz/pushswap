/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:42:35 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/02 18:22:22 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
};

struct s_stack_info
{
	int				size;
	struct s_stack	*head;
	struct s_stack	*tail;
};

//	error:	Takes an error message, prints it and exits the program.
void			error(const char *error_message);

//	free_mem:	Frees the memory to free and exits the program.
void			free_mem(char **mem_to_free);

//	free_and_exit:	Takes memory to free, frees it, prints a message to the
//					console and exits the program.
void			free_and_exit(char **mem_to_free);

//	check_duplicates:	Conversts the string passed to it to array of ints
//						 and checks if any of the numbers are duplicates. 
//						 If so, returns an error message and exits the program,
//						 else returns the array of int.
int				*check_duplicates(const char *str, struct s_stack_info *l_info);

//	check_consecutive_spaces:	Checks all arguments for embedded spaces in them
//								prints and error message when found and exits
//								the program.
void			check_consecutive_spaces(char **argv);

//	Init_list:	Initializes a linked list after confirming the arguments are
//				valid.
struct s_stack	*init_stack_a(struct s_stack_info *l_info, int *valid_ints);

//	pa:	Takes two stacks and pushes the top of b to the top of a.
//		It returns nothing.
void			pa(struct s_stack **a, struct s_stack **b);

//	pb:	Takes two stacks and pushes the top of a to the top of b.
//		It returns nothing.
void			pb(struct s_stack **b, struct s_stack **a);

#endif
