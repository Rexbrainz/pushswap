/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:42:35 by sudaniel          #+#    #+#             */
/*   Updated: 2024/12/11 09:45:18 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

struct s_node
{
	int				value;
	int				pos;
	int				index;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
};

struct s_stack
{
	int				size;
	int				new_size;
	struct s_node	*head;
	struct s_node	*tail;
	struct s_node	*best_move_node;
};

//	check_argv:	Takes the arguments passed, checks if they are valid,
//				if valid, initialized stack a with them.
void	check_argv(struct s_stack *a, char **argv);

//	error:	Takes an error message, prints it to STDERR and exits the program.
void	error(const char *error_message);

//	free_mem:	Frees the memory to free and exits the program.
void	free_mem(char **mem_to_free);

//	free_and_exit:	Takes memory blocks to free, frees them
//					and  prints a message to STDERR  and exits the program.
void	free_and_exit(char **mem_to_free, char *str);

// handle_checker_error: Frees the two stacks when the checker finds
// 							an error.
void	handle_checker_error(struct s_stack *a, struct s_stack *b);

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

//	push:	Takes two stacks and pushes the first node in src to dst.
void	push(struct s_stack *dst, struct s_stack *src);

//	pa:	Takes two stacks and pushes the top of b to the top of a.
//		It returns nothing.
void	pa(struct s_stack *a, struct s_stack *b);

//	pb:	Takes two stacks and pushes the top of a to the top of b.
//		It returns nothing.
void	pb(struct s_stack *b, struct s_stack *a);

//	swap:	Takes a stack and swaps it's first two nodes.
void	swap(struct s_stack *stack);

//	sa:	Takes a stack, swaps its first two elements, 
//		if there is one or less it does nothing.
void	sa(struct s_stack *a);

//	sb:	Takes a stack, swaps its first two elements,
//		 if there is one or less it does nothing.
void	sb(struct s_stack *b);

//	ss:	Takes two stacks, and swaps the first two element in each of the stacks
//		If there is one or less in any of them, it does nothing for the stack
//		with one or less elements in it.
void	ss(struct s_stack *a, struct s_stack *b);

//	rotate:	Takes a stack and rotates it, such that the first becomes the last.
void	rotate(struct s_stack *stack);

//	ra:	Takes stack a, shifts all its element up by one and makes the first 
//		element become the last.
void	ra(struct s_stack *a);

//	rb:	Takes stack b, shifts all its element up by one and makes the first 
//		element become the last.
void	rb(struct s_stack *b);

//	rr:	Performs ra and rb at the same time.
void	rr(struct s_stack *a, struct s_stack *b);

//	reverse_rotate:	Takes a stack and rotates it, such that the last becomes
//					 the first.
void	reverse_rotate(struct s_stack *stack);

//	rra:	Takes stack a, shifts all its element down by one
//			and makes the last element become the first.
void	rra(struct s_stack *a);

//	rrb:	Takes stack b, shifts all its element down by one and makes the last
//		element become the first.
void	rrb(struct s_stack *b);

//	rrr:	Performs rra and rrb at the same time.
void	rrr(struct s_stack *a, struct s_stack *b);

//	sort:	Takes both stacks, checks the status of stack size and sorts
//			accordingly.
void	sort(struct s_stack *a, struct s_stack *b);

//	is_sorted: Takes stack a and checks if it is sorted, returns a bool.
bool	is_sorted(struct s_stack *stack);

//	sort_three:	Takes a stack with three nodes and sorts them.
void	sort_three(struct s_stack *a);

//	stack_sort:	Takes both stacks and sorts them.
void	stack_sort(struct s_stack *a, struct s_stack *b);

//	push_all_but_three:	Takes both stacks and pushes nodes from a to b.
//						It pushes to b such that half of stack b seems
//						roughly sorted.
void	push_all_but_three(struct s_stack *a, struct s_stack *b);

//	find_cheapest_move: Indentifies the cheapest node to move.
void	find_cheapest_move(struct s_stack *a, struct s_stack *b);

//	execute_moves: Takes both stacks, execute pushswap instructions based
//					on the cheapest move to make.
void	execute_moves(struct s_stack *a, struct s_stack *b);

//	free_stack: Takes stack a and frees it.
void	free_stack(struct s_stack *a);

#endif
