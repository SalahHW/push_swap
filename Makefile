# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 05:33:03 by sbouheni          #+#    #+#              #
#    Updated: 2023/05/27 03:00:38 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
CFLAGS = 	-Wall -Wextra -Werror -g -fsanitize=address
COMPILE = 	$(CC) $(CFLAGS)
NAME =		push_swap
BONUS_NAME = checker
RM		:= rm -f

MAIN_SRC = push_swap.c

SRCS	:=	utils/int_convert_utils.c utils/cost_utils.c utils/list_utils.c		\
			utils/parser_utils.c utils/list_movements.c utils/utils.c src/cost.c\
			src/cost_calculation.c src/cost_application.c src/parser.c			\
			src/sort.c src/position.c movement/swap.c							\
			movement/push.c movement/reverse_rotate.c movement/rotate.c			\

SRCS_BONUS =	checker.c

OBJS        := $(MAIN_SRC:.c=.o) $(SRCS:.c=.o)

OBJB		:= $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS}
	make -C libft
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ./libft -lft

all:		${NAME}

${BONUS_NAME} : ${OBJB}
	${CC} ${CFLAGS} -o ${BONUS_NAME} ${OBJB} -L ./libft -lft

bonus: ${BONUS_NAME} ${NAME}


clean:
	${RM} *.o */*.o */*/*.o

fclean:		clean
	${RM} ${NAME}
	${RM} ${BONUS_NAME}
	cd ./libft && make $@

re:			fclean all

.PHONY:		all clean fclean re


