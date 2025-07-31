# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 20:12:03 by aphyo-ht          #+#    #+#              #
#    Updated: 2025/07/27 17:07:45 by aphyo-ht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

MAINFILE = main.c

SFILES = strings.c files.c chars.c

LIBNAME = libmylib.a

LIB = mylib

SDIR = srcs/

HEADDIR = includes

SOURCES = ${addprefix ${SDIR},${SFILES}}

OBJECTS = ${SOURCES:.c=.o}

all: ${NAME}

%o: %c
.c.o:
	${COMPILER} ${CFLAGS} -c -I ${HEADDIR} $< -o ${<:.c=.o}

${LIBNAME}: ${OBJECTS}
	${AR} ${LIBNAME} ${OBJECTS}

${NAME}: ${LIBNAME} ${MAINFILE}
	${COMPILER} ${CFLAGS} -g ${MAINFILE} -L . -l${LIB} -I ${HEADDIR}/ -o ${NAME}

clean:
	rm -f ${OBJECTS} ${LIBNAME}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: re all clean fclean
