# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 14:54:20 by vorhansa          #+#    #+#              #
#    Updated: 2026/03/09 18:08:54 by vorhansa         ###   ########.fr        #
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
			initialize.c \
			push.c	\
			swap.c \
			rotate.c \
			r_rotate.c \
			index.c \
			sort.c \
			radix.c \
			
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

# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

# number of arg
size ?= $(shell read -p "Enter size: " size_input && echo $$size_input)

#CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
CHECKER = ./push_swap $(ARG) | ./checker_linux $(ARG)

test:
	@$(MAKE) all
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@echo "Checker result: "
	$(CHECKER)
	@echo "Instructions count: "
	@./push_swap $(ARG) | wc -l
	@$(MAKE) fclean

.PHONY: all clean fclean re test