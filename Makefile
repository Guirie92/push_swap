# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 21:58:38 by guillsan          #+#    #+#              #
#    Updated: 2025/11/27 21:46:26 by guillsan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src
SRCS_ALGORITHMS = $(SRCS_DIR)/algorithms
SRCS_PARSER = $(SRCS_DIR)/parser
SRCS_UTILS = $(SRCS_DIR)/utils
SRCS_OP = $(SRCS_DIR)/op
SRCS_SOLVER = $(SRCS_DIR)/solver

SRCS = $(addprefix $(SRCS_DIR)/,         \
		push_swap.c)                     \
		$(addprefix $(SRCS_ALGORITHMS)/, \
		quick_sort.c)                    \
		$(addprefix $(SRCS_PARSER)/,     \
		rankify.c                        \
		parser.c)                        \
		$(addprefix $(SRCS_UTILS)/,      \
		stack_ops.c)                     \
		$(addprefix $(SRCS_OP)/,         \
		push.c                           \
		rev_rotation.c                   \
		rotation.c                       \
		swap.c)                          \
		$(addprefix $(SRCS_SOLVER)/,     \
		chunk_sort.c                     \
		sort_handler.c)
		

OBJS = $(SRCS:.c=.o)

LIB_DIR = libft
LIB_FILE = $(LIB_DIR)/libft.a

INC = -I inc
INC_LIB = -I $(LIB_DIR)/inc

# Compilation and Linking Flags
C_INCLUDES = $(INC) $(INC_LIB) 
# Links the Libft lib and its path
LDFLAGS = -L $(LIB_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS) $(LIB_FILE)
	@$(CC) $(CFLAGS) $(C_INCLUDES) $(OBJS) $(LDFLAGS) -o $(NAME)

# Rule to build the libft lib
$(LIB_FILE):
	@make -C $(LIB_DIR)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(C_INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIB_DIR)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.DEFAULT_GOAL=all