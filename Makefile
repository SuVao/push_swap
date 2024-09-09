# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 15:15:44 by pesilva-          #+#    #+#              #
#    Updated: 2024/09/07 18:14:04 by pesilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
RM = rm -f
FLAGS = -Wall -Werror -Wextra -g
INCLUDES = ./includes/
SRC_DIR = ./src/
LIBFT = ./libs/Libft/

SRC = 	main.c \
		ft_free.c \
		rev_rotate.c \
		push.c \
		rotate.c \
		swap.c \
		utils.c \
		sort_3.c \
		sort_4.c \
		sort_big.c \
		stackar.c \
		str_utils.c \
		checkagem.c \
		calc_moves.c \
		calc_moves2.c \
		utils2.c \
		utils3.c \

SRC_BONUS = checker.c

HEADER = -Iincludes


SRC := $(addprefix $(SRC_DIR), $(SRC))

OBJ = ${SRC:.c=.o}

%.o: %.c
	${CC} ${FLAGS} ${HEADER} -c $< -o $@

${NAME}: ${OBJ} $(LIBFT)
	@echo "Compiling LIBFT"
	@make re -C ${LIBFT}
	@${CC} ${FLAGS} ${OBJ} -L${LIBFT} -lft -o ${NAME}

all: ${NAME}

$(LIBFT):
	@make -C $(LIBFT_DIR)

bonus: ${NAME_BONUS}

clean:
	${RM} ${OBJ} ${OBJ_BONUS}
	@make clean -C $(LIBFT)

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
