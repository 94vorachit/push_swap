# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 14:54:20 by vorhansa          #+#    #+#              #
#    Updated: 2026/02/24 18:24:14 by vorhansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap
INCS		= -I./include
LIBFT 		= ./libft/libft.a

SRC_DIR =	src
SRC		=	check_input.c	\
			main.c	\
# SRCS	=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR	=	obj
OBJ		=	$(SRC:.c=.o)
OBJS 	= 	$(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c -o $@ $^

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# all: $(OBJ_PATH) $(NAME) 

# $(OBJ_PATH)%.o: $(SRC_PATH)%.c
# 	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
# $(OBJ_PATH):
# 	mkdir $(OBJ_PATH)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


# all: $(NAME) $(BONUS)

# $(OBJ_DIR)/%.o: ./src/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

# $(NAME): $(LIBFT) $(OBJ) 
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
# $(LIBFT):
# 	@$(MAKE) -C ./libft