#***********************************************************************************************#
#                                           PUSH-SWAP                                           #
#***********************************************************************************************#

# Variables
NAME := push_swap
CC := cc
CFLAGS := -g -Wall -Wextra -Werror
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

SRC := main.c	errors.c 	check_duplicates.c\
   	   initialize_list.c	push.c	swap.c\
	   rotate.c	reverse_rotate.c	sort.c\
	   stack_sort.c	execute.c	execute_rrr.c\
	   execute_rr.c
OBJ := $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

# Phony Targets
.PHONY: all clean fclean re
