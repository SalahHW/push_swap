# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 06:11:36 by sbouheni          #+#    #+#              #
#    Updated: 2023/03/06 22:44:44 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g3
COMPILE =	$(CC) $(CFLAGS)
NAME =		push_swap.a
LIBNAME =	libft.a

SRC_DIR =		./src/
INCLUDE_DIR =	./includes/
LIBFT_DIR = 	./libft/
OBJ_DIR =		./obj/

SRC = 	$(SRC_DIR)push_swap.c 							\
		$(SRC_DIR)push_to.c \
		$(SRC_DIR)extract_values.c

OBJ =	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(COMPILE) -c -o $@ $<

clean :
	rm -rf $(OBJ_DIR) 
	cd $(LIBFT_DIR) && $(MAKE) $@

fclean : clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) && $(MAKE) $@

test :	$(NAME) $(TESTFILE)
	$(COMPILE) -o push_swap $(SRC_DIR)push_swap.c $(NAME) 

re : fclean all

.PHONY : libft
