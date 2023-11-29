# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 16:12:55 by ycontre           #+#    #+#              #
#    Updated: 2023/11/29 13:31:15 by ycontre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_BONUS	=	checker

CC			=	cc

CFLAGS		=	-g -Wall -Wextra -Werror

INCLUDE		=	-I.

LIB			=	-L./libft -lft

SRCS		=	mandatory/srcs/push_swap.c						\
				mandatory/srcs/errors_handling.c				\
				mandatory/srcs/operations.c						\
				mandatory/srcs/utils_stack.c					\
				mandatory/srcs/algorithm.c						\
				mandatory/srcs/algorithm_helper.c				\
				mandatory/srcs/utils.c

SRCS_BONUS	=	bonus/srcs/checker.c							\
				bonus/srcs/utils_stack.c						\
				bonus/srcs/utils.c								\
				bonus/srcs/errors_handling.c					\
				bonus/srcs/solve_stdin.c						\
				bonus/srcs/operations.c							\
				bonus/srcs/operations_both.c							\

OBJS		= 	${SRCS:.c=.o}

OBJS_BONUS	= 	${SRCS_BONUS:.c=.o}

LIBPATH		= 	libft/

all:			${NAME}

${NAME}:		${OBJS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o $@

bonus:			${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o ${NAME_BONUS}

clean:
			make clean -C ${LIBPATH}
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			make fclean -C ${LIBPATH}
			rm -f ${NAME} ${NAME_BONUS} ${NAME_TEST}

re:				fclean all

.PHONY:			all clean fclean re