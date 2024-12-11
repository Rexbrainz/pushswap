#******************************************************************************************#
#                                      PUSH-SWAP                                           #
#******************************************************************************************#

# Variables
NAME := push_swap
BONUS_NAME := checker

CC := cc
CFLAGS := -g -Wall -Wextra -Werror
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

SRC :=	main.c	check_arguments.c	check_duplicates.c\
		initialize_list.c	push.c	swap.c	rotate.c reverse_rotate.c\
		sort.c	 stack_sort.c find_cheapest_move.c	execute_moves.c\
		push_all_but_three.c free_and_error.c
BONUS_SRC := checker.c	check_arguments.c	check_duplicates.c\
		initialize_list.c	push.c	swap.c	rotate.c reverse_rotate.c\
		free_and_error.c push_all_but_three.c

OBJ := $(SRC:.c=.o)
BONUS_OBJ := $(BONUS_SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all bonus

# Phony Targets
.PHONY: all clean fclean re bonus

