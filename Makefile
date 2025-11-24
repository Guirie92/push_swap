# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 21:58:38 by guillsan          #+#    #+#              #
#    Updated: 2025/11/24 14:52:43 by guillsan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS_DIR = src

SRCS = $(addprefix $(SRCS_DIR)/,        \
		push_swap.c)  

OBJS = $(SRCS:.c=.o)

LIB_DIR = libft
LIB_FILE = $(LIB_DIR)/libft.a

INC_MINI = -I inc
INC_LIB = -I $(LIB_DIR)/inc

# --- Compilation and Linking Flags ---
C_INCLUDES = $(INC_MINI) $(INC_LIB) 
# Links the Libft lib and its path
LDFLAGS = -L $(LIB_DIR) -lft


all: $(NAME)

$(NAME): $(OBJS) $(LIB_FILE)
	@$(CC) $(CFLAGS) $(C_INCLUDES) $(OBJS) $(LDFLAGS) -o $(NAME)


# -------------------------------- TEST AREA --------------------------------- #

run: $(NAME)
	./$(NAME) $(ARGS)

rerun:
	@make -s fclean
	@make -s all
	./$(NAME) $(ARGS)

# -------------------------------- TEST AREA --------------------------------- #

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

.PHONY: all clean fclean re $(LIB_FILE)

.DEFAULT_GOAL=all