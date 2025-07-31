# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 08:11:59 by aphyo-ht          #+#    #+#              #
#    Updated: 2025/07/30 10:15:16 by aphyo-ht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCEFILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

HEADERFILES = ft.h

SRCDIR = srcs

HEADERDIR = includes

SOURCES = ${addprefix ${SRCDIR}/, ${SOURCEFILES}}

HEADERS = ${addprefix ${HEADERDIR}/, ${HEADERFILES}}

OBJECTS = ${SOURCES:.c=.o}

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

COMPILER = cc

.c.o:
	${COMPILER} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}


${NAME}: ${OBJECTS}
	${AR} ${NAME} ${OBJECTS}

all: ${NAME}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
