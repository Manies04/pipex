# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 12:58:33 by tiade-al          #+#    #+#              #
#    Updated: 2024/10/25 12:59:39 by tiade-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 

SRC = srcs/main.c \

CC = @cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo " [ .. ] | Compiling.."
	@make -s -C $(LIBFT_PATH)
	@echo " [ OK ] | Ready!"

clean:
	@rm -f $(OBJS)
	@echo "object files removed."
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "all files created were removed."

re: fclean all

.PHONY:	all clean fclean re