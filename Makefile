# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 23:24:17 by tpassin           #+#    #+#              #
#    Updated: 2024/11/04 18:28:55 by tpassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

HEADER_DIR	= includes

SRCS = srcs/parsing.c \
	   srcs/main.c \
	   srcs/init.c \
	   srcs/utils_philo.c \
	   srcs/routine.c \
	   srcs/actions.c \

OBJS = ${SRCS:.c=.o}

CC = clang

CFLAGS = -Wall -Werror -Wextra -pthread -g3 -fsanitize=thread

RM = rm -f

$(NAME): ${OBJS}
	${CC}  ${CFLAGS} ${OBJS} -o $(NAME)

%.o:%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I $(HEADER_DIR)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:  all clean fclean re