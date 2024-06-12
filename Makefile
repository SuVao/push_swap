# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 15:15:44 by pesilva-          #+#    #+#              #
#    Updated: 2024/06/08 15:27:44 by pesilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = CCRM = rm -f
FLAGS = -Wall -Werror -Wextra
LIBFTDIR = libft/
OBJ_DIR = obr/
SRC_DIR = srcs/

SRC_1 = srcs/push_swap.c \

SRC_2 = srcs/checkagem.c \
		srcs/ft_free.c \
		srcs/push.c \
		srcs/rev_rotate.c \
		srcs/rotate.c \
		srcs/sort_3.c \
		srcs/sort_5.c \
		srcs/sort_big.c \
		srcs/stackar.c \
		srcs/str_utils.c \
		srcs/swap.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus