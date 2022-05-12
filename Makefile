# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 16:24:28 by shogura           #+#    #+#              #
#    Updated: 2022/05/11 19:38:24 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=
CLIENT = client
SERVER = server

LIBFT = ./libft/libft.a

SRC_C = src/client.c
SRC_S = src/server.c

CFLAG= -Wall -Wextra -Werror
RM = rm -f

NR = norminette -R CheckForbiddenSourceHeader

all:${CLIENT} ${SERVER}

${NAME}:all

${SERVER}:${SRC_S} ${LIBFT}
	${CC} ${CFLAG} $^ -o $@

${CLIENT}:${SRC_C} ${LIBFT}
	${CC} ${CFLAG} $^ -o $@

${LIBFT}:
	cd ./libft;${MAKE}

fclean:
	${RM} ${CLIENT} ${SERVER}
	cd ./libft;${MAKE} fclean
