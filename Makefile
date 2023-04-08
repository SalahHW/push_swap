# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 06:11:36 by sbouheni          #+#    #+#              #
#    Updated: 2023/04/08 10:28:59 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g3
COMPILE =	$(CC) $(CFLAGS)
NAME =		push_swap.a
LIBNAME =	libft.a
PROG = ./push_swap

SRC_DIR =			./src/
MOVEMENT_DIR = ./movement/
INCLUDE_DIR =	./include/
LIBFT_DIR = 	./libft/
OBJ_DIR =			./obj/

SRC = 	main.c															\
				$(SRC_DIR)list_utils.c		 					\
				$(SRC_DIR)list_movements.c 					\
				$(SRC_DIR)int_convert_utils.c				\
				$(MOVEMENT_DIR)swap.c 							\
				$(MOVEMENT_DIR)push.c								\
				$(MOVEMENT_DIR)rotate.c							\
				$(MOVEMENT_DIR)reverse_rotate.c	

OBJ =		$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

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
	rm -rf $(OBJ_DIR) $(PROG)
	cd $(LIBFT_DIR) && $(MAKE) $@

fclean : clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) && $(MAKE) $@

$(PROG) : $(NAME)
	$(COMPILE) -o $(PROG) main.c $(NAME) 

debug : $(PROG) 
	lldb $(PROG) # "-10" "20" "30" "40" "50"  

re : fclean all

.PHONY : libft
