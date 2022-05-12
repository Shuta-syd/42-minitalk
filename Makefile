# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 16:24:28 by shogura           #+#    #+#              #
#    Updated: 2022/05/12 16:54:40 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=
CLIENT = client
SERVER = server

PRINTF_PATH = src/ft_printf
PRINTF = ${PRINTF_PATH}/ft_printf.c ${PRINTF_PATH}/ft_printf_utils.c ${PRINTF_PATH}/output_utils.c\
	${PRINTF_PATH}/format_scan.c ${PRINTF_PATH}/print_d_i.c ${PRINTF_PATH}/print_u.c\
	${PRINTF_PATH}/print_xX.c ${PRINTF_PATH}/print_p.c ${PRINTF_PATH}/print_s.c ${PRINTF_PATH}/print_c_per.c
SRC_C = src/client.c src/minitalk_utils.c
SRC_S = src/server.c src/minitalk_utils.c

CFLAG= -Wall -Wextra -Werror
RM = rm -f

NR = norminette -R CheckForbiddenSourceHeader

all:${CLIENT} ${SERVER}

${NAME}:all

${SERVER}:${SRC_S} ${PRINTF}
	${CC} ${CFLAG} $^ -o $@

${CLIENT}:${SRC_C} ${PRINTF}
	${CC} ${CFLAG} $^ -o $@

nr:${SRC_S} ${SRC_C} ${PRINTF}
	${NR} $^

fclean:
	${RM} ${CLIENT} ${SERVER}
