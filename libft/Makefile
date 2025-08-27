# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 10:00:40 by bbeceiro          #+#    #+#              #
#    Updated: 2025/08/20 10:00:47 by bbeceiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

# Source files 
SRCS	=	ft_isdigit.c \
			ft_strlen.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_atol.c \
			ft_atoi.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_substr.c \
			ft_split.c \
			ft_putstr_fd.c

# Create object files list (.o)
OBJS	= $(SRCS:.c=.o)

# Rules
all: $(NAME)

# Create the library archive
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS)

# Full clean (objects + library)
fclean: clean
	$(RM) $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re