# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 15:15:44 by pesilva-          #+#    #+#              #
#    Updated: 2024/06/20 14:33:16 by pesilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

RM = rm -f
FLAGS = -Wall -Werror -Wextra

SRC = 	main.c \
		ft_free.c \
		rev_rotate.c \
		push.c \
		rotate.c \
		swap.c \
		utils.c \
		sort_3.c \
		sort_5.c \
		sort_big.c \
		stackar.c \
		str_utils.c \
		checkagem.c \

OBJ = ${SRC:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}
	

all: ${NAME}

clean:
	${RM} ${OBJ} ${NAME}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re bonus