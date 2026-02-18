# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 14:54:20 by vorhansa          #+#    #+#              #
#    Updated: 2026/02/16 18:50:02 by vorhansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC_PATH	= src/
OBJ_PATH	= obj/

SRC			=
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
INCS		= -I ./include/
LIBFT 		= ./libft/libft.a

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCS) -c -o $@ $^

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: fclean all


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