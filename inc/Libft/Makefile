# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 11:41:01 by tiade-al          #+#    #+#              #
#    Updated: 2024/04/30 17:13:14 by tiade-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c ft_isalnum.c ft_isprint.c ft_memcmp.c\
ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_strlcpy.c\
ft_strchr.c  ft_strlcpy.c ft_putnbr_fd.c\
ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_itoa.c\
ft_memmove.c ft_strdup.c  ft_strlen.c  ft_strrchr.c \
ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memset.c ft_memcpy.c \
ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
ft_striteri.c ft_memchr.c ft_strlcat.c\
ft_strjoin.c ft_strtrim.c ft_strmapi.c

OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstsize.c ft_lstnew.c ft_lstadd_front.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstiter.c ft_lstmap.c ft_lstclear.c

BONUS_OBJ		= $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 

NAME			= libft.a

all:			$(NAME)
$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(BONUS) $(BONUS_OBJ) 
				ar rcs $(NAME) $(BONUS_OBJ)

clean:
				$(RM) $(OBJS) $(BONUS_OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME) 

.PHONY:			all clean fclean re bonus