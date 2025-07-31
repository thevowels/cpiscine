CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = bsq

SOURCES = bsq_main_mapzapper.c bsq_mapzapper_subroutines.c bsq_sub_parse.c bsq_sub_mark.c bsq_main_helpers.c utils.c bsq_parse_utils.c

SRCDIR = srcs/

SRCS = ${addprefix ${SRCDIR},${SOURCES}}

HDIR = includes

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c -I${HDIR}  ${HEAD} $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
