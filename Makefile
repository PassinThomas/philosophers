# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 23:24:17 by tpassin           #+#    #+#              #
#    Updated: 2024/06/27 23:43:16 by tpassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SRCS = srcs/parsing.c \
	   srcs/main.c \

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g3 -g -Wall -Werror -Wextra

RM = rm -f

$(NAME): ${OBJS}
	${CC} ${OBJS} -o $(NAME)

%.o:%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:  all clean fclean re