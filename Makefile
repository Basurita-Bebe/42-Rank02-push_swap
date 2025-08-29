# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 09:43:32 by bbeceiro          #+#    #+#              #
#    Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

# Libraries
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Includes
INCLUDES = -I./includes -I$(LIBFT_DIR)

# Source files
SRCS = \
	 srcs/main.c \
	 srcs/parsing/parse_args.c \
	 srcs/parsing/input_validation.c \
	 srcs/parsing/init_stack_a.c \
	 srcs/stack/stack_utils.c \
	 srcs/stack/stack_ops_1.c \
	 srcs/stack/stack_ops_2.c \
	 srcs/stack/stack_ops_3.c \
	 srcs/sort/small_sort.c \
	 srcs/sort/big_sort.c \
	 srcs/utils/error_handler.c \
	 srcs/utils/utils.c \
	 srcs/utils/free.c	\
	 srcs/testing.c

# Object files director
OBJS = $(SRCS:.c=.o)

# Color for output
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m

# Rules
all: $(LIBFT) $(NAME)

# Compile libft first
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compiled successfully!$(RESET)"

# Compile main program
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Compile each .c file into a .o file
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)✓ Object files removed!$(RESET)"

# Full clean (objects + executables + library)
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(YELLOW)✓ $(NAME) and libft cleaned!$(RESET)"

# Recompile everything
re: fclean all

# Avoid conflicts with files names
.PHONY: all clean fclean re