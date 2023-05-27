# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 18:12:50 by sbouheni          #+#    #+#              #
#    Updated: 2023/05/25 05:15:38 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
CFLAGS = 	-Wall -Wextra -Werror -g
COMPILE = 	$(CC) $(CFLAGS)
NAME =		libft.a

SRC =		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c	\
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c 		\
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c		\
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c		\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c			\
			ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c			\
			ft_split.c ft_itoa.c ft_striteri.c ft_putnbr_fd.c ft_strmapi.c		\
			get_next_line.c get_next_line_utils.c								\


BONUS_SRC =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c		\
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c		\
			ft_lstclear_bonus.c ft_lstsize_bonus.c ft_lstiter_bonus.c			\
			ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus : $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean :
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
