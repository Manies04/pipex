# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 12:58:33 by tiade-al          #+#    #+#              #
#    Updated: 2024/11/28 01:04:39 by tiade-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = srcs/main.c srcs/cleaners.c srcs/doers.c srcs/helpers.c\
	srcs/helpers2.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

CC = @cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./inc/Libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo " [ .. ] | Compiling Libft..."
	@make -s -C $(LIBFT_PATH)
	@echo " [ OK ] | Libft ready!"

$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "All files created were removed."

re: fclean all

.PHONY: all clean fclean re
